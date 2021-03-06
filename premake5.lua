function file_check(file_name)
  local file_found=io.open(file_name, "r")      
  return file_found
end

newoption {
   trigger     = "sciter",
   value       = "PATH",
   description = "Path of sciter-sdk.",
}

function includeSciter()
  if not _OPTIONS["sciter"] then
    printf("Please provide path to sciter-sdk. using --sciter=PATH argument.\n")
    return
  end

  local file = file_check(_OPTIONS["sciter"] .. "/include/sciter-x.h")
  if file ~= nil then
    includedirs { _OPTIONS["sciter"] .. "/include" }
  else
    printf("Can't find sciter sdk at given path.\n");
    os.exit()
  end
end	

function includeHaru()
  includedirs {"./sub-modules/libharu/build/include", "./sub-modules/libharu/include"}
  libdirs {"./sub-modules/libharu/build/src", "./sub-modules/libharu/build/src/Release"} 
  --links "libhpdfs"
end	

workspace "sciter-pdf"
    location "build"
    configurations { "DebugStatic", "DebugDLL", "ReleaseStatic", "ReleaseDLL" }
    platforms { "Win32", "Win64" }
    
    cppdialect "C++14" 

    staticruntime "On"

    startproject "sciter-pdf" 

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"

    filter "platforms:Win32"
        system "Windows"
        architecture "x86"

    filter "platforms:Win64"
        system "Windows"
        architecture "x86_64"

outputdir = "lib/"
    
project "sciter-pdf"
    language "C++"
    filter "system:windows"
      files {"sciter-pdf.def" }
    filter {}

    files {
        "./sub-modules/libharu/src/*.c",
        "./sub-modules/libharu/include/*.h",
        "PDF.cpp",
        "PDF.h",
        "Page.cpp",
        "Doc.cpp",
        "Image.cpp"
    }
    
    includeSciter()
    includeHaru()    
    
    filter "*Static"
      kind "StaticLib"

    filter "*DLL"
      kind "SharedLib"