#include "sdl_exceptions.h"

Exception::Exception(std::string fnc){
    err_msg = "ERR: " + SDL_GetError() + ", from " + fnc;
}
