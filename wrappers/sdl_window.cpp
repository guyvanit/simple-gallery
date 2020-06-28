#include "sdl_window.h"
#include "sdl_exceptions.h"

Window::Window(const std::string &title, int x, int y, int w, int h, Uint32 flags){

    // initalise SDL Window object and test for NULL
    win_ = SDL_CreateWindow(title.c_str(), x, y, w, h, flags);
    if(win_==NULL){
        // throw Exception("Window class constructor");
        throw;
    }

}

Window::~Window(){
    SDL_DestroyWindow(win_);
}

SDL_Window* Window::get_window(){
    return win_;
}


