if not exist /build (
    mkdir build
)

cd build

if not exist /Debug (
    mkdir Debug
)

cmake -G "Visual Studio 17 2022" -A Win32 -S "../" -B "."
cmake --build "." --config Debug
xcopy /s "../libs/SFML/bin/" "Debug/" /f /y
for %%# in ("Debug/*.exe") do start Debug/%%#