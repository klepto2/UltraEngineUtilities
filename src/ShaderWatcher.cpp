
#include "UltraEngine.h"
#include "../include/ShaderCompiler/ShaderWatcher.h"

using namespace UltraEngine;
using namespace UltraEngine::Utilities::Shader;
using namespace UltraEngine::Utilities::Shader::Internal;
using namespace std;


void UltraEngine::Utilities::Shader::ShaderWatcher::RunPreprocess(vector<shared_ptr<ShaderFile>> files)
{
	int time = Millisecs();
	Print("Preprocessing... (" + WString(files.size()) + " Shaders)");

	vector<shared_ptr<Thread>> threads;

	for (auto f : files)
	{
		threads.push_back(CreateThread(bind(ThreadPreprocess,_compiler, f), true));
	}

	for (auto t : threads)
		t->Wait();

	Print("Preprocessing finished... (" + WString(Millisecs() - time) + "ms)");
}

void UltraEngine::Utilities::Shader::ShaderWatcher::RunCompilation(vector<shared_ptr<ShaderFile>> files)
{
	auto time = Millisecs();
	Print("Compiling... (" + WString(files.size()) + " Shaders)");

	vector<shared_ptr<Thread>> threads;

	for (auto f : files)
	{
		Print("Compiling... \"" + f->GetSource() + "\"");
		threads.push_back(CreateThread(bind(ThreadCompile, _compiler, f), true));
	}

	for (auto t : threads)
		t->Wait();

	Print("Compilation finished... (" + WString(Millisecs() - time) + "ms)");

	for (auto f : files)
	{
		auto result = f->GetResult();
		if (result->HasError())
		{
			if (f->Parents.size() > 0)
			{
				Print("Error in ShaderFiles:");
				for (auto p : f->Parents)
					Print(p);
				Print("----------------------------------");
			}
			Print(result->GetError());
		}
		else
		{
			auto asset = FindCachedAsset(RealPath(f->GetTarget()).Lower());
			auto engine = UltraEngine::Core::GameEngine::Get()->cachedassets;
			if (asset)
			{
				asset->Reload();
			}
		}
	}

}

bool UltraEngine::Utilities::Shader::ShaderWatcher::ProcessWatcherEvent(const Event& ev)
{
	auto ext = ExtractExt(ev.text);
	auto filetype = FileType(ev.text);

	switch (ev.id)
	{
		case EVENT_FILECHANGE:
			if (ext == "json" && filetype == 2)
			{
				auto new_files = _collector->Update(false);
				RunPreprocess(new_files);
				RunCompilation(_collector->GetShaderFilesWhichNeedsCompiling());
			}
			else if (_compiler->IsShaderFile(ext))
			{
				WString path = ev.text.Replace(AppDir() + "/", "");
				auto file = _collector->GetFile(path);
				vector<shared_ptr<ShaderFile>> files_to_compile;

				if (file != NULL)
				{
					files_to_compile.push_back(file);
				}
				else
				{
					auto filestoCompile = _collector->GetShaderFilesIncludingFile(ev.text);
					files_to_compile.insert(files_to_compile.begin(), filestoCompile.begin(), filestoCompile.end());
				}

				RunCompilation(files_to_compile);
			}
			break;
		case EVENT_FILECREATE:
			if (ext == "json" && filetype == 2)
			{
				auto new_files = _collector->Update(false);
				RunPreprocess(new_files);
				RunCompilation(_collector->GetShaderFilesWhichNeedsCompiling());
			}
			break;
		case EVENT_FILERENAME:
			break;
		case EVENT_FILEDELETE:
			break;
	}

	return false;
}

UltraEngine::Utilities::Shader::ShaderWatcher::ShaderWatcher()
{
	_compiler = CreateShaderCompiler();
	_collector = CreateShaderCollector();
}

void UltraEngine::Utilities::Shader::ShaderWatcher::Start()
{
	auto items = _collector->Update(true);
	RunPreprocess(_collector->GetAllFiles());
	RunCompilation(_collector->GetShaderFilesWhichNeedsCompiling());

	_watcher = CreateFileSystemWatcher(AppDir() + "/Shaders", true);
	ListenEvent(EVENT_FILECHANGE,NULL, &FileSystemShaderWatcherCallback, Self());
	ListenEvent(EVENT_FILECREATE,NULL, &FileSystemShaderWatcherCallback, Self());
	ListenEvent(EVENT_FILERENAME,NULL, &FileSystemShaderWatcherCallback, Self());
	ListenEvent(EVENT_FILEDELETE,NULL, &FileSystemShaderWatcherCallback, Self());
}

bool UltraEngine::Utilities::Shader::FileSystemShaderWatcherCallback(const Event& ev, shared_ptr<Object> extra)
{
	auto watcher = extra->As<ShaderWatcher>();
	if (watcher != NULL)
	{
		return watcher->ProcessWatcherEvent(ev);
	}

	return true;
}

void UltraEngine::Utilities::Shader::ThreadPreprocess(shared_ptr<ShaderCompiler> compiler, shared_ptr<ShaderFile> file)
{
	auto result = compiler->Preprocess(file->GetSource());
	file->SetResult(result);
}

void UltraEngine::Utilities::Shader::ThreadCompile(shared_ptr<ShaderCompiler> compiler, shared_ptr<ShaderFile> file)
{
	auto result = compiler->Compile(file->GetSource(), file->GetTarget());
	file->SetResult(result);
}

shared_ptr<ShaderWatcher> UltraEngine::Utilities::Shader::CreateShaderWatcher()
{
	return make_shared<ShaderWatcher>();
}
