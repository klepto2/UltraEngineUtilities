#pragma once
#include "UltraEngine.h"
#include "ShaderCompiler.h"

using namespace UltraEngine;
using namespace UltraEngine::Utilities::Shader;
using namespace std;

namespace UltraEngine::Utilities::Shader::Internal
{
	class ShaderFile : Object
	{
	private:
		WString _source;
		WString _target;
		uint64_t _lastCompilationTime;
		shared_ptr<CompilationResult> _lastCompilationResult;
	public:
		vector<WString> Parents;

		ShaderFile(WString source, WString target) : _source(source), _target(target)
		{
		}

		WString GetTarget() { return _target; }
		WString GetSource() { return _source; }

		void SetResult(shared_ptr<CompilationResult> result) {
			_lastCompilationResult = result;
			if (_lastCompilationResult->HasError())
			{
				_lastCompilationTime = FileTime(_source);
			}
		}

		shared_ptr<CompilationResult> GetResult() {
			return _lastCompilationResult;
		}

		bool ContainsResource(WString file)
		{
			if (_lastCompilationResult != NULL)
			{
				auto includes = _lastCompilationResult->GetIncludedFiles();
				auto it = find(includes.begin(), includes.end(), file);

				if (it != includes.end())
				{
					return true;
				}
			}

			return false;
		}

		bool NeedsCompilation()
		{
			return (_lastCompilationResult != NULL && _lastCompilationResult->HasError())
				? FileTime(_source) > _lastCompilationTime
				: FileTime(_target) < FileTime(_source);
		}
	};

	class ShaderCollector : public Object
	{
	private:
		vector<shared_ptr<ShaderFile>> _shaderFiles;

		void ParseShaderFamily(WString filename, nlohmann::json& data)
		{
			for (auto& i : data.items()) {

				auto value = i.value();
				auto key = i.key();

				if (!value.is_string()
					&& !value.is_null()
					&& !value.is_number()
					&& !value.is_boolean())
				{
					ParseShaderFamily(filename, value);
				}
				else
				{
					if (value.is_string())
					{
						auto data = value.get<std::string>();
						if (ExtractExt(data) == "spv")
						{
							auto filetoSearch = StripAll(data);
							auto f = FindFile(filetoSearch);
							f = f.Replace(CurrentDir() + "/", "");
							bool exists = false;
							for (auto sf : _shaderFiles)
							{
								if (sf->GetTarget() == data)
								{
									if (find(sf->Parents.begin(), sf->Parents.end(), filename) == sf->Parents.end())
									{
										sf->Parents.push_back(filename);
									}

									exists = true;
									break;
								}
							}
							if (!exists && f != "")
							{
								auto file = make_shared<ShaderFile>(f, data);
								file->Parents.push_back(filename);
								_shaderFiles.push_back(file);
							}

						}
					}
				}
			}
		}

		void Collect(WString path)
		{
			auto dir = LoadDir(path);

			if (path == "") path = ".";

			for (auto file : dir)
			{
				if (path != "") file = path + "/" + file;

				auto ext = ExtractExt(file);
				auto filetype = FileType(file);

				if (filetype != 2 &&
					(ext == "json"))
				{
					auto json = LoadJson(file);
					ParseShaderFamily(file, json);
				}

				if (filetype == 2)
				{
					Collect(file);
				}
			}
		}

	public:
		vector<shared_ptr<ShaderFile>> Update(bool clear = true)
		{
			WString path = AppDir() + "/Shaders";

			if (clear)
				_shaderFiles.clear();

			vector<shared_ptr<ShaderFile>> files(_shaderFiles);

			Collect(path);

			vector<shared_ptr<ShaderFile>> newfiles;
			for (auto f : _shaderFiles)
				if (find(files.begin(), files.end(), f) == files.end())
					newfiles.push_back(f);

			return newfiles;
		}

		vector<shared_ptr<ShaderFile>> GetAllFiles()
		{
			return _shaderFiles;
		}

		shared_ptr<ShaderFile> GetFile(WString filename)
		{
			auto it = find_if(_shaderFiles.begin(), _shaderFiles.end(), [&filename](shared_ptr<ShaderFile> obj) {return obj->GetSource() == filename; });

			if (it != _shaderFiles.end())
			{
				return *it;
			}


			return NULL;
		}

		vector<shared_ptr<ShaderFile>> GetShaderFilesIncludingFile(WString filename)
		{
			vector<shared_ptr<ShaderFile>> files;

			for (auto f : _shaderFiles)
			{
				if (f->ContainsResource(filename))
					files.push_back(f);
			}

			return files;
		}

		vector<shared_ptr<ShaderFile>> GetShaderFilesWhichNeedsCompiling()
		{
			vector<shared_ptr<ShaderFile>> files;

			for (auto f : _shaderFiles)
			{
				if (f->NeedsCompilation())
					files.push_back(f);
			}

			return files;
		}
	};


	inline shared_ptr<ShaderCollector> CreateShaderCollector()
	{
		return make_shared<ShaderCollector>();
	}
}
