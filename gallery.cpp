#include <iostream>
#include <algorithm>
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

    // try printing the vector of dirs
    for(const auto &path : *imgDirs){
        std::cout << path << std::endl;
    }

    return 0;

}

std::unique_ptr<PathVector> getImgDirs(std::string &path){
    // returns smart pointer to names of all images in path directory

    // initalise image extensions set AND smart pointer to vector to contain image paths
    std::set<std::string> imgExtensions {".JPG", ".BMP", ".GIF", ".PNG"};
    std::unique_ptr<PathVector> dirs(new PathVector);

    // fetch all the files in specified directory -> edit this later
    for(const auto &entry : fs::directory_iterator(path)){

        // checks if entry is a file -> if not, skip to next loop
        if(!entry.is_regular_file()){
            continue;
        }

        // obtains file extension -> uppercased for comparison
        std::string ext = entry.path().extension();
        std::transform(ext.begin(), ext.end(), ext.begin(), toupper);

        // add file to vector if extension is in imgExtensions
        if(imgExtensions.find(ext) == imgExtensions.end()){
            dirs->push_back(entry.path());
        }
    }

    return dirs;

}


