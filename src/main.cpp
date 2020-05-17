#include <iostream>
#include <memory>
#include <SDL/SDL.h>
//#ifdef __EMSCRIPTEN__
#include <emscripten.h>
//#endif
//Declarations
std::shared_ptr<SDL_Surface> CreateSurface(unsigned int width, unsigned int height);
void LockSurfaceIfNeeded(const std::shared_ptr<SDL_Surface>& surface);
void DrawSomething(const std::shared_ptr<SDL_Surface>& surface);
void UnlockSurfaceIfNeeded(const std::shared_ptr<SDL_Surface>& surface);
void FlipSurface(const std::shared_ptr<SDL_Surface>& surface);

int main(int argc, char** argv){
    std::cout<<"foo bar"<<std::endl;
    SDL_Init(SDL_INIT_VIDEO);
    std::shared_ptr<SDL_Surface> screen = CreateSurface(256, 256);
    LockSurfaceIfNeeded(screen);
    DrawSomething(screen);
    UnlockSurfaceIfNeeded(screen);
    FlipSurface(screen);
    SDL_Quit();
    return 0;
}
//Definitions, separated from declarations as is the Will Of God.
std::shared_ptr<SDL_Surface> CreateSurface(unsigned int width, unsigned int height){
    std::shared_ptr<SDL_Surface> surf(SDL_SetVideoMode(width,height, 32, SDL_SWSURFACE));
    return surf;
}

void LockSurfaceIfNeeded(const std::shared_ptr<SDL_Surface>& surface){
    if (SDL_MUSTLOCK(surface)) {
        SDL_LockSurface(surface.get());
    }
}
void DrawSomething(const std::shared_ptr<SDL_Surface>& surface){
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            int alpha = (i+j) % 255;
            *((Uint32*)surface->pixels + i * 256 + j) = SDL_MapRGBA(surface->format, i, j, 255-i, alpha);
        }
    }
}
void UnlockSurfaceIfNeeded(const std::shared_ptr<SDL_Surface>& surface){
    if (SDL_MUSTLOCK(surface)) {
        SDL_UnlockSurface(surface.get());
    }
}

void FlipSurface(const std::shared_ptr<SDL_Surface>& surface){
    SDL_Flip(surface.get());
}
