#include <iostream>
#include <memory>
#include <set>

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

// header -> includes <filesystem>, <vector> and <string>
#include "gallery.h"

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

    // get all image file names in specified path
    std::unique_ptr<PathVector> imgDirs = getImgDirs(path);

    return 0;

}

std::unique_ptr<PathVector> getImgDirs(std::string &path){
    // returns smart pointer to names of all images in path directory

    // initalise set containing valid file extensions to use to filter
    std::set<std::string> imgExtensions;
    imgExtensions.insert(".JPG");
    imgExtensions.insert(".BMP");
    imgExtensions.insert(".GIF");
    imgExtensions.insert(".PNG");

    // fetch all the files in specified directory -> edit this later
    for(const auto &entry : fs::directory_iterator(path)){
        std::cout << entry.path() << std::endl;
    }

}


