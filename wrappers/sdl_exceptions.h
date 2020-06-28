#include <SDL2/SDL.h>
#include <string>

class Exception{
    std::string err_msg;

    public:
        Exception(std::string fnc);
        ~Exception();

};
