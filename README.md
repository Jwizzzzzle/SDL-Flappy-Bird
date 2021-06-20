# SDL-FlappyBird

This is a Flappy Bird clone built with c++ and SDL2. In order to build you will need [msvc command line](https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio-2019) - its the "Build Tools for Visual Studio 2019", [SDL2 for VC](https://www.libsdl.org/download-2.0.php), and [SDL2_image for VC](https://www.libsdl.org/projects/SDL_image/). Make a sdl directory in the main directory. Put the include folder in there and the SDL2.lib and SDL2_image.lib files. Then place all .dll files in the main directory. Finally open MSVC command line and run this command in the main directory:
```
cl /EHsc src/*.cpp /link /OUT:game.exe /DEFAULTLIB:sdl/SDL2.lib /DEFAULTLIB:sdl/SDL2_image.lib
```
I followed the [Codergophers SDL2 RPG series](https://www.youtube.com/playlist?list=PL2RPjWnJduNmXHRYwdtublIPdlqocBoLS) to learn the basics of SDL2.