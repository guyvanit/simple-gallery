#include <iostream>
#include <string>
#include <filesystem>

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

namespace fs = std::filesystem;

int main(int argc, char** args){

    // DEFAULT PATH -> current directory
    std::string path = "./";

    for(const auto &entry : fs::directory_iterator(path)){
        std::cout << entry.path() << std::endl;
    }

    return 0;

}
