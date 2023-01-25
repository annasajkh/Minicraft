if exist build\ (
    cd build
) else (
    mkdir build
    cd build
)

cmake -G "Visual Studio 17 2022" -A Win32 -S ../ -B "x86-Release"
cmake --build x86-Release --config Release
xcopy /s "../libs/SFML/bin" "x86-Release/Release/" /f /y
for %%# in ("x86-Release/Release/*.exe") do start "" x86-Release/Release/%%#