#include <iostream>
#include <algorithm>
#include <memory>
#include <set>

// #include <SDL2_image/SDL_image.h>

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
        }else{

            // if exists -> check if it's NOT a directory
            if(!fs::is_directory(path)){
                std::cerr << "Error: Path given is not a directory." << std::endl;
                return -1;
            }
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
    Uint32 flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
    SDLwrap::Window win = SDLwrap::Window("SDL Gallery", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, flags);
    SDLwrap::Renderer ren = SDLwrap::Renderer(win, -1, SDL_RENDERER_ACCELERATED);
    SDLwrap::Texture tex = SDLwrap::Texture();

    // initialise rendering colour
    ren.setDrawColor(0xFF, 0xFF, 0xFF, 0xFF);

    // ----------- OBTAIN IMAGE FILE NAMES -----------

    // get all image file names in specified path
    std::unique_ptr<PathVector> imgDirs = getImgDirs(path);

    // check if images found in directory -> print error and exit
    if(imgDirs->size() <= 0){
        std::cout << std::endl << "No images found in directory: " << path << std::endl << std::endl;
        return -1;
    }

    // print all the image file names obtained
    std::cout << std::endl << "Image files found: " << std::endl;
    for(const auto &path : *imgDirs){
        std::cout << path << std::endl;
    }
    std::cout << std::endl;

    // --------- INITIAL LOADING ---------

    int index = 0;

    std::string fname = imgDirs->at(index);;
    // std::cout << fname << std::endl;
    tex.loadFile(ren, fname);

    // ----------- RENDERING LOOP -----------

    bool running = true;
    SDL_Event event;

    while(running){

        while(SDL_PollEvent(&event)){
            // ends loop if user closes window
            if(event.type == SDL_QUIT){
                running = false;
            }else if(event.type == SDL_KEYDOWN){

                keydown_handler(event, index, imgDirs->size());
                // std::cout << "index: " << index << std::endl;

                fname = imgDirs->at(index);
                try{
                    tex.loadFile(ren, fname);
                }catch(SDLwrap::Exception &e){

                    std::cout << std::endl << "SDL Error occured from: " << e.get_fnc() << std::endl;
                    std::cout << "SDL Error: " << e.get_err() << std::endl << std::endl;

                    // handles the error here:
                    // erase the missing file from vector + move onto next loop
                    imgDirs->erase(imgDirs->begin() + index);
                    continue;

                }
            }
        }

        // clear screen
        ren.setDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
        ren.clear();

        // get texture to fit to window size?
        tex.fit_window = &win;

        // centers image during rendering
        tex.FLAG_RENDER_CENTER = true;
        // set flag to auto scale image according to window size
        tex.FLAG_SCALE_IMG = true;
        // set flag to scale window to texture when loading new texture
        tex.FLAG_SCALE_WIN = true;

        // renders texture
        tex.render(ren);
        ren.update();

        // 16ms delay as we try to keep each "frame" ~<17ms
        SDL_Delay(16);

    }

    std::cout << std::endl;
    return 0;

}

void keydown_handler(SDL_Event &event, int &index, int size){
    // handles keydown event

    switch(event.key.keysym.sym){

        case SDLK_LEFT:
            index = (index-1) % size;
            if(index<0){
                index = size + index;
            }
            break;

        case SDLK_RIGHT:
            index = (index+1) % size;
            break;

        default:
            break;

    }

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
    std::set<std::string> imgExtensions {".JPG", ".BMP", ".GIF", ".PNG", ".JPEG"};
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

    // sort the file names
    std::sort(dirs->begin(), dirs->end());

    return dirs;

}


