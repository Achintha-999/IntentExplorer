@echo off
echo Compiling leaderboard system...
clang++ -std=c++11 -Wall src/main.cpp src/user.cpp src/database_simulated.cpp -o leaderboard.exe
if %errorlevel% equ 0 (
    echo Build successful!
    echo.
    leaderboard.exe
) else (
    echo Build failed!
)
pause