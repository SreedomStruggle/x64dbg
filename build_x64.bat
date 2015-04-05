@echo off
echo Setting Qt in PATH
set PATH=%PATH%;c:\Qt\qt-4.8.6-x64-msvc2013\qt-4.8.6-x64-msvc2013\bin
set PATH=%PATH%;c:\Qt\qtcreator-3.1.1\bin
CALL "c:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\vcvarsall.bat" amd64

echo Building DBG...
devenv /Rebuild "Release|x64" x64_dbg.sln

echo GUI prebuildStep
cd x64_dbg_gui\Project
cmd /k "prebuildStep.bat x64"
cd ..
cd ..

echo Building GUI...
rmdir /S /Q build
mkdir build
cd build
qmake ..\x64_dbg_gui\Project\x64_dbg.pro CONFIG+=release
jom
cd ..

echo GUI afterbuildStep
cd x64_dbg_gui\Project
call afterbuildStep.bat x64 ..\..\build\release
cd ..
cd ..