#include "UltraEngine.h"
#include "../include/ShaderCompiler/ShaderCompiler.h"
#include "../include/ShaderCompiler/ShaderFileCollector.hpp"

using namespace UltraEngine;
using namespace UltraEngine::Utilities::Shader::Internal;

shared_ptr<UltraEngine::Utilities::Shader::CompilationResult> UltraEngine::Utilities::Shader::CompilationResult::Create(shaderc_compilation_status result, WString error_msg, std::vector<WString> includes)
{
	auto compilationResult = std::make_shared<CompilationResult>();
	compilationResult->_result = result;
	compilationResult->_error_msg = error_msg;
	compilationResult->_includeData = includes;
	return compilationResult;
}

WString UltraEngine::Utilities::Shader::CompilationResult::GetError()
{
	return _error_msg;
}

bool UltraEngine::Utilities::Shader::CompilationResult::HasError()
{
	return !_error_msg.empty();
}

bool UltraEngine::Utilities::Shader::CompilationResult::IsSuccesfull()
{
	return _result == shaderc_compilation_status::shaderc_compilation_status_success;
}

shaderc_compilation_status UltraEngine::Utilities::Shader::CompilationResult::GetStatus()
{
	return _result;
}

vector<WString> UltraEngine::Utilities::Shader::CompilationResult::GetIncludedFiles()
{
	return _includeData;
}

UltraEngine::Utilities::Shader::ShaderCompiler::ShaderCompiler()
{
	
}

shared_ptr<UltraEngine::Utilities::Shader::CompilationResult> UltraEngine::Utilities::Shader::ShaderCompiler::Compile(WString sourcepath, WString targetpath)
{
	vector<WString> includes;
	CompileOptions _compilerOptions;
	_compilerOptions.SetLimit(shaderc_limit_max_draw_buffers, 255);
	_compilerOptions.SetOptimizationLevel(shaderc_optimization_level_zero);
	_compilerOptions.SetTargetSpirv(shaderc_spirv_version_1_6);
	_compilerOptions.SetIncluder(std::make_unique<ShaderFileCollector>(ExtractDir(sourcepath).ToString(), includes));

	if (FileType(sourcepath) == 0)
	{
		return CompilationResult::Create(shaderc_compilation_status_internal_error, "File not found : \"" + sourcepath + "\"", includes);
	}

	auto source = LoadString(sourcepath) + "\r\n";

	auto ext = ExtractExt(sourcepath);
	shaderc_shader_kind kind = ext_to_shader_kind[ext];

	auto result = _compiler.CompileGlslToSpv(
		source.c_str(), kind, sourcepath.ToString().c_str(), _compilerOptions);


	if (result.GetCompilationStatus() != shaderc_compilation_status_success) {
		return CompilationResult::Create(result.GetCompilationStatus(), result.GetErrorMessage(), includes);
	}

	auto binary = std::vector<uint32_t>(result.begin(), result.end());
	auto stream = WriteFile(targetpath);

	if (stream == NULL)
	{
		return CompilationResult::Create(shaderc_compilation_status_internal_error, "Failed to write to : \"" + targetpath + "\"" , includes);
	}

	for (auto data : binary)
	{
		stream->WriteInt(data);
	}

	stream->Close();

	return CompilationResult::Create(shaderc_compilation_status_success, "", includes);
}

shared_ptr<UltraEngine::Utilities::Shader::CompilationResult> UltraEngine::Utilities::Shader::ShaderCompiler::Preprocess(WString sourcepath)
{
	vector<WString> includes;

	CompileOptions _compilerOptions;
	_compilerOptions.SetLimit(shaderc_limit_max_draw_buffers, 255);
	_compilerOptions.SetOptimizationLevel(shaderc_optimization_level_zero);
	_compilerOptions.SetTargetSpirv(shaderc_spirv_version_1_6);
	_compilerOptions.SetIncluder(std::make_unique<ShaderFileCollector>(ExtractDir(sourcepath).ToString(), includes));

	if (FileType(sourcepath) == 0)
	{
		return CompilationResult::Create(shaderc_compilation_status_internal_error, "File not found : \"" + sourcepath + "\"", includes);
	}

	auto source = LoadString(sourcepath) + "\r\n";

	auto ext = ExtractExt(sourcepath);
	shaderc_shader_kind kind = ext_to_shader_kind[ext];

	auto result = _compiler.PreprocessGlsl(
		source.c_str(), kind, sourcepath.ToString().c_str(), _compilerOptions);

	if (result.GetCompilationStatus() != shaderc_compilation_status_success) {
		return CompilationResult::Create(result.GetCompilationStatus(), result.GetErrorMessage(), includes);
	}

	return CompilationResult::Create(shaderc_compilation_status_success, "", includes);
}

bool UltraEngine::Utilities::Shader::ShaderCompiler::IsShaderFile(WString extension)
{
	return ext_to_shader_kind.find(extension.Lower()) != ext_to_shader_kind.end();
}

shared_ptr<UltraEngine::Utilities::Shader::ShaderCompiler> UltraEngine::Utilities::Shader::CreateShaderCompiler()
{
	return std::make_shared<ShaderCompiler>();
}
