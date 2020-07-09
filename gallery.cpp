#include <iostream>
#include <algorithm>
#include <memory>
#include <set>

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include "gallery.h"
#include "SDLwrap/SDL_WRAP.h"

namespace fs = std::filesystem;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char** args){

    // ------ HANDLE COMMAND LINE ARGS ------
    /*
        Takes in 1 extra command-line argument
            - path -> specifies the directory to run our gallery on
              (if none given -> uses current directory)
    */

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

    // ------------ SDL Initalisation ------------

    // initalise SDL environment
    SDLwrap::SDL sdl = SDLwrap::SDL(SDL_INIT_VIDEO);

    // set up SDL_IMG for handling JPG + PNG
    SDLwrap::SDL_IMG sdl_img = SDLwrap::SDL_IMG(IMG_INIT_JPG | IMG_INIT_PNG);

    // initalise SDL objects
    SDLwrap::Window win = SDLwrap::Window("SDL Gallery", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDLwrap::Renderer ren = SDLwrap::Renderer(win, -1, SDL_RENDERER_ACCELERATED);
    SDLwrap::Texture tex = SDLwrap::Texture();

    // obtain managed renderer
    SDL_Renderer* renderer = ren.get_renderer();

    // initialise rendering colour
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    // ----------- LOAD IMAGE TEST -----------

    std::string fpath = "test_img.jpg";
    tex.loadFile(ren, fpath);

    // ----------- RENDER TEST -----------

    bool running = true;
    SDL_Event event;

    while(running){

        while(SDL_PollEvent(&event)){
            // ends loop if user closes window
            if(event.type == SDL_QUIT){
                running = false;
            }
        }

        // clear screen
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);

        // renders texture
        tex.render(ren);
        SDL_RenderPresent(renderer);

        // 16ms delay as we try to keep each "frame" ~<17ms
        SDL_Delay(16);

    }

    return 0;

}

std::unique_ptr<PathVector> getImgDirs(std::string &path){
    /*
        Example use:

            // get all image file names in specified path
            std::unique_ptr<PathVector> imgDirs = getImgDirs(path);

            // print all the image file names obtained
            for(const auto &path : *imgDirs){
                std::cout << path << std::endl;
            }
    */

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


