#include <iostream>
#include <SDL2/SDL.h>

#include "sdl_exceptions.h"

Exception::Exception(std::string f){
    fnc_ = f;
    sdl_err_ = SDL_GetError();
}

std::string Exception::get_err(){
    return sdl_err_;
}

std::string Exception::get_fnc(){
    return fnc_;
}

