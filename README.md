# UltraEngineUtilities

UltraEngineUtilities is a repostiory where I will publish some of my own Utilities to help work in www.ultraEngine.com.

Current Version: 
A first version of a Shader Compiler is added, which uses shaderc as a backend and let you simply 
compile shaders on the fly via runtime. I already have a kind of shader watcher running, but this will take a few days
untill this will be released. 

Features:
class ShaderCompiler:
      - Compilation and saving of shaderfiles to spv format.
        - return a result object, not only containing the result status but also a list of includes used by that particular shader
          (useful for the later watcher).
      - Preprocessing a shader without saving it.
        - return a result object, not only containing the result status but also a list of includes used by that particular shader
          (useful for the later watcher).
          
Usage:

1. Add the path to the shaderc_shared.lib under "external\libs" to your lib folders
2. Add #include "include/Utilities.h" to your code

Sample:
```cpp
#include "UltraEngine.h"
#include "ComponentSystem.h"

#include "include\Utilities.h"

using namespace UltraEngine;
using namespace UltraEngine::Utilities::Shader;

int main(int argc, const char* argv[])
{
    auto compiler = CreateShaderCompiler();
    auto result = compiler->Compile("Shaders/GUI/WidgetBlock.frag", "Shaders/GUI/WidgetBlock.frag.spv");
    if (result->IsSuccesfull())
    {
        Print("Shader compiled succesfully!");
        for (auto f : result->GetIncludedFiles())
        {
            Print("Shader includes: " + f);
        }
    }
    else
    {
        Print("Shader compilation failed!");
        Print(result->GetError());
    }
    ...
}
```
      
