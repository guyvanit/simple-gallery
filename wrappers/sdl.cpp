#include "sdl.h"

SDL::SDL(Uint32 flags){
    if(SDL_Init(flags)){
        throw Exception("SDL::SDL()");
    }
}

SDL::~SDL(){
    SDL_Quit();
}
