#pragma once

#include "UltraEngine.h"
#include "ShaderCompiler.h"
#include "ShaderCollector.hpp"

using namespace UltraEngine;
using namespace UltraEngine::Utilities::Shader;
using namespace UltraEngine::Utilities::Shader::Internal;
using namespace std;

namespace UltraEngine::Utilities::Shader
{
	bool FileSystemShaderWatcherCallback(const Event& ev, shared_ptr<Object> extra);
	void ThreadPreprocess(shared_ptr<ShaderCompiler> compiler, shared_ptr<ShaderFile> file);
	void ThreadCompile(shared_ptr<ShaderCompiler> compiler, shared_ptr<ShaderFile> file);

	class ShaderWatcher : public Object
	{
	private:
		shared_ptr<ShaderCompiler> _compiler;
		shared_ptr<ShaderCollector> _collector;
		shared_ptr<FileSystemWatcher> _watcher;
		void RunPreprocess(vector<shared_ptr<ShaderFile>> files);
		void RunCompilation(vector<shared_ptr<ShaderFile>> files);
		bool ProcessWatcherEvent(const Event& ev);
	public:
		ShaderWatcher();
		void Start();

		friend bool FileSystemShaderWatcherCallback(const Event& ev, shared_ptr<Object> extra);
	};


	shared_ptr<ShaderWatcher> CreateShaderWatcher();
}
