#include "sdl_window.h"
#include "sdl_exceptions.h"

Window::Window(const std::string &title="SDL test", int x=SDL_WINDOWPOS_UNDEFINED, int y=SDL_WINDOWPOS_UNDEFINED,
                int w=640, int h=480, Uint32 flags=SDL_WINDOW_SHOWN){

    // initalise SDL Window object and test for NULL
    win = SDL_CreateWindow(title.c_str(), x, y, w, h, flags);
    if(win==NULL){
        // throw Exception("Window class constructor");
        throw;
    }

}


