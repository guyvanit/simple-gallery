#include <iostream>
#include <algorithm>
#include <memory>
#include <set>

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

// header -> includes <filesystem>, <vector> and <string>
#include "gallery.h"
#include "wrappers/sdl_window.h"

namespace fs = std::filesystem;
using std::cout;
using std::cerr;
using std::endl;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char** args){

    // -- handle command line arguments --
    std::string path;
    if(argc==1){
        // DEFAULT PATH -> current directory
        path = "./";
    }else if(argc==2){

        // takes in command line argument as directory
        // -> checks if path does not exist -> return error
        path = args[1];
        if(!fs::exists(path)){
             cerr << "Error: Directory does not exist or not found." << endl;
             return -1;
        }

    }else{
        cerr << "Error: Invalid number of command line arguments." << endl;
        return -1;
    }

    // initalise the required environments
    if(!init()){
        cerr << "Error: Failed initalisiation. " << endl;
    }else{

        // get all image file names in specified path
        std::unique_ptr<PathVector> imgDirs = getImgDirs(path);

        // try printing the vector of dirs
        for(const auto &path : *imgDirs){
            cout << path << endl;
        }

    }

    return 0;

}

bool init(){
    // initalise SDL, SDL_IMG + other environments
    bool success = true;

    // initalise SDL environment
    if(SDL_Init(SDL_INIT_VIDEO)){
        cerr << "Error: Failed SDL Initalisiation. " << SDL_GetError() << endl;
        success = false;
    }else{

        cout << "Successful SDL Initalisation" << endl;

        // initalise SDL window
        g_Window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(g_Window == NULL){
            cerr << "Error: SDL Window cannot be created. " << SDL_GetError() << endl;
            success = false;
        }else{

            // initalise SDL renderer
            g_Renderer = SDL_CreateRenderer(g_Window, -1, SDL_RENDERER_ACCELERATED);
            if(g_Renderer == NULL){
                cout << "Error: Renderer failed initliasiation. " << SDL_GetError() << endl;
                success = false;
            }else{

                // set colour of renderer initialsation
                SDL_SetRenderDrawColor(g_Renderer, 0xFF, 0xFF, 0xFF, 0xFF);

                // initalise SDL_IMG environment
                // -> set up for loading JPG + PNG images
                int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG;
                if( (IMG_Init(imgFlags)&imgFlags) != imgFlags){
                    cout << "Error: SDL_image failed initialization. " << IMG_GetError() << endl;
                    success = false;
                }
            }
        }
    }

    return success;

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
        if(imgExtensions.find(ext) != imgExtensions.end()){
            dirs->push_back(entry.path());
        }
    }

    return dirs;

}


