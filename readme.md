# Hello SDL
The next step is to see something of the SDL library on screen.

## SDL
Emscripten comes with at least SDL1. Most documentation that I find in the internet guarantees that it can 
always use SDL1 as the emscripten team reimplemented it as part of their Library. Looking at the includes 
directory I saw SDL2 too, so I assume that at May/2020 they ship SDL2 too.

SDL - "Simple Directmedia Layer is a cross-platform development library designed to provide low level
access to audio, keyboard, mouse, joystick, and graphics hardware via OpenGL and Direct3D. It is 
used by video playback software, emulators, and popular games including Valve's award winning 
catalog and many Humble Bundle games.". If I remember correctly it began as a DirectX wrapper that gave
portability to the games because the game would use the wrapper and the wrapper would be implemented using
the target system's libraries.

### Drawing something on the screen
- Initialize SDL with video subsystem. (```SDL_Init```)
- Set the video mode (```SDL_SetVideoMode```), that gives me a SDL_Surface. A SDL_Surface is a collection
of pixels used in blitting.
- Then I lock the surface (```SDL_LockSurface```). I must lock the surface to be able to write on it`s pixels.
- Then I draw something, setting the pixels, they are a member of SDL_Surface. Setting pixel-by-pixel as I am  
doing in this example is slow and most certainly there are better ways.
- When I finished drawing I must unlock the surface (```SDL_UnlockSurface```).
- Finally I flip the buffers:```SDL_Flip```. The backbuffer, the one in which I drew the things becomes the 
front buffer being shown and the former front buffer becomes the back buffer in which the next drawings can be
done.

## Emscritpten Envoronment

### Toolchain file
Instead of using emcmake/emmake I can use the toolchain file I found. Just remember to 
remove the WASM=0 parameters from the cmake configuration. 

### Testing if I am compiling in an emscripten environment
The flag ```__EMSCRIPTEN__``` says if I am under emscripten or not. Example:
```
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif
```

### Seeing the emscripten directories
Using the toolchain file or emcmake is not enough. I must add the include directories to the project using
```include_directories("~/emsdk/emscripten/1.38.30/system/include")``` or the symbols won't be there in the world
of c++

### Running the program locally
The program now assumes the machine has docker installed. The run_in_docker.sh command deploys the program to a docker
container.

### Deploying to the server
It can also be deployed to a server. run_in_heroku.sh deploys to my heroku account, so it's available for all to see.
