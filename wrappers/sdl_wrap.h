#ifndef SDL_WRAP
#define SDL_WRAP

#include <SDL2/SDL.h>
#include <string>

class Window{

    SDL_Window* win;

    public:

        // constuctor + destructor to manage SDL_Window
        // NOTE -> may need to create more constructors to handle arguments to SDL_CreateWindow()
        Window(const std::string& title, int x, int y, int w, int h, Uint32 flags);
        ~Window();

        // copy constructor + copy assignment operator
        // -> do not allow copy of resources of Window class
        Window(const Window& that) = delete;
        Window& operator=(const Window& that) = delete;

};

#endif
