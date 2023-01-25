if exist build\ (
    cd build
) else (
    mkdir build
    cd build
)

cmake -G "Visual Studio 17 2022" -A Win32 -S ../ -B "x86-Debug"
cmake --build x86-Debug --config Debug
xcopy /s "../libs/SFML/bin" "x86-Debug/Debug/" /f /y
for %%# in ("x86-Debug/Debug/*.exe") do start "" x86-Debug/Debug/%%#