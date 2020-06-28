#ifndef SDL_WINDOW
#define SDL_WINDOW

#include <SDL2/SDL.h>
#include <string>

class Window{

    SDL_Window* win_;

    public:

        // constuctor + destructor to manage SDL_Window
        // NOTE -> may need to create more constructors to handle arguments to SDL_CreateWindow()
        Window(const std::string &title="SDL test", int x=SDL_WINDOWPOS_UNDEFINED, int y=SDL_WINDOWPOS_UNDEFINED,
                int w=640, int h=480, Uint32 flags=SDL_WINDOW_SHOWN);
        ~Window();

        // copy constructor + copy assignment operator
        // -> do not allow copy of resources of Window class
        Window(const Window& that) = delete;
        Window& operator=(const Window& that) = delete;

        // getter for managed SDL_Window
        SDL_Window* get_window();

};

#endif
