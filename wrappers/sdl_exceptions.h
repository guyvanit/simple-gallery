#ifndef SDL_EXS
#define SDL_EXS
#include <string>

class Exception{
    std::string sdl_err_;
    // stores which function causes the exception to be thrown
    std::string fnc_;

    public:
        // constructor + (default) destructor?
        Exception(std::string f);

        // getters -> would storing as char[] use less memory/better?
        std::string get_err();
        std::string get_fnc();

};

#endif
