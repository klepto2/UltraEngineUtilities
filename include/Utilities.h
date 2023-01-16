#pragma once
#pragma comment(lib, "shaderc_shared.lib")

#if _DEBUG
#pragma comment(lib, "Scintilla_d.lib")
#pragma comment(lib, "Lexilla_d.lib")
#else
#pragma comment(lib, "Scintilla.lib")
#pragma comment(lib, "Lexilla.lib")
#endif

#pragma comment(lib, "imm32")

#include "ShaderCompiler/ShaderCompiler.h"
#include "ShaderCompiler/ShaderWatcher.h"

#include "../external/submodules/scintilla/include/ScintillaTypes.h"
#include "../external/submodules/scintilla/include/ScintillaMessages.h"
#include "../external/submodules/scintilla/include/ScintillaStructures.h"
#include "../external/submodules/scintilla/include/ScintillaCall.h"
#include "../external/submodules/scintilla/include/Scintilla.h"

#include "../external/submodules/scintilla/include/ILexer.h"
#include "../external/submodules/lexilla/include/Lexilla.h"
#include "../external/submodules/lexilla/include/SciLexer.h"

#include "UI/SyntaxWidget.h"
#include "../include/UI/ScintillaLexer.h";





