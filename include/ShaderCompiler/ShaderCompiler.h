#pragma once

#include "UltraEngine.h"
#include "../../external/includes/shaderc.hpp"

using namespace UltraEngine;
using namespace shaderc;

namespace UltraEngine::Utilities::Shader
{
    class ShaderCompiler;
    // The CompilationResult class stores the result of a shader compilation.
    // It contains information about the status of the compilation, any errors that occurred,
    // and any included files.
    class CompilationResult : public Object
    {
        friend class ShaderCompiler;

    private:
        // Creates a new CompilationResult with the given compilation status, error message, and included files.
        static shared_ptr<CompilationResult> Create(shaderc_compilation_status result, WString error_msg, std::vector<WString> includes);
        // The error message, if any, from the compilation.
        WString _error_msg;

        // The included files, if any, from the compilation.
        vector<WString> _includeData;

        // The status of the compilation.
        shaderc_compilation_status _result;
    public:
       
        // Returns the error message, if any, from the compilation.
        WString GetError();

        // Returns true if there was an error during compilation, false otherwise.
        bool HasError();

        // Returns true if the compilation was successful, false otherwise.
        bool IsSuccesfull();

        // Returns the status of the compilation.
        shaderc_compilation_status GetStatus();

        // Returns the included files, if any, from the compilation.
        vector<WString> GetIncludedFiles();

    };

    // The ShaderCompiler class provides methods for compiling and preprocessing shaders.
    class ShaderCompiler : public Object
    {
    private:
        // The shaderc compiler object.
        Compiler _compiler;


        inline static std::unordered_map<std::wstring, shaderc_shader_kind> ext_to_shader_kind = {
    {L"vert", shaderc_shader_kind::shaderc_glsl_vertex_shader},
    {L"frag", shaderc_shader_kind::shaderc_glsl_fragment_shader},
    {L"geom", shaderc_shader_kind::shaderc_glsl_geometry_shader},
    {L"tese", shaderc_shader_kind::shaderc_glsl_tess_evaluation_shader},
    {L"tesc", shaderc_shader_kind::shaderc_glsl_tess_control_shader},
    {L"comp", shaderc_shader_kind::shaderc_glsl_compute_shader},
        };

    public:

        ShaderCompiler();
        // Compiles the shader at the given source path and writes the result to the given target path.
        // Returns a CompilationResult object containing information about the compilation.
        shared_ptr<CompilationResult> Compile(WString sourcepath, WString targetpath);

        // Preprocesses the shader at the given source path.
        // Returns a CompilationResult object containing information about the preprocessing.
        shared_ptr<CompilationResult> Preprocess(WString sourcepath);

        bool IsShaderFile(WString extension);
    };

    // Creates and returns a new ShaderCompiler object.
    shared_ptr<ShaderCompiler> CreateShaderCompiler();
}