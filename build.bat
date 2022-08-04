@echo off

echo Looking for vswhere.exe...
set "vswhere=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
if not exist "%vswhere%" set "vswhere=%ProgramFiles%\Microsoft Visual Studio\Installer\vswhere.exe"
if not exist "%vswhere%" (
	echo ERROR: Failed to find vswhere.exe
	exit /b 1
)
echo Found %vswhere%

echo Looking for VC...
for /f "usebackq tokens=*" %%i in (`"%vswhere%" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do (
  set vc_dir=%%i
)
if not exist "%vc_dir%\Common7\Tools\vsdevcmd.bat" (
	echo ERROR: Failed to find VC tools x86/x64
	exit /b 1
)
echo Found %vc_dir%
echo %vc_dir%

if not exist "%vc_dir%\MSBuild\Current\Bin\MSBuild.exe" (
	echo ERROR: Failed to find MSBuild tool.
	exit /b 1
)
call "%vc_dir%\MSBuild\Current\Bin\MSBuild.exe" -v:d build/sciter-pdf.vcxproj /p:configuration=ReleaseStatic /p:platform=x64
echo Built sciter-pdf