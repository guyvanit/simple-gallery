#include <iostream>
#include <string>
#include <filesystem>

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

namespace fs = std::filesystem;

int main(int argc, char** args){

    // configure command line arguments
    std::string path;
    if(argc==1){

        // DEFAULT PATH -> current directory
        path = "./";

    }else if(argc==2){

        // takes in command line argument as directory
        // -> checks if path does not exist -> return error
        path = args[1];
        if(!fs::exists(path)){
             std::cerr << "Error: Directory does not exist or not found." << std::endl;
             return -1;
        }

    }else{
        std::cerr << "Error: Invalid number of command line arguments." << std::endl;
        return -1;
    }

    // fetch all the files in specified directory
    for(const auto &entry : fs::directory_iterator(path)){
        std::cout << entry.path() << std::endl;
    }

    return 0;

}
