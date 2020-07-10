#ifndef GALLERY
#define GALLERY

// ------- H-REQUIRED INCLUDES -------

#include <filesystem>
#include <string>
#include <vector>

#include <SDL2/SDL.h>

// ------- VARIABLE DECLARATIONS -------

// vector containing path to some file
typedef std::vector<std::filesystem::path> PathVector;

// ------- FUNCTION DECLARATIONS -------

// returns smart pointer to names of all images in path directory
std::unique_ptr<PathVector> getImgDirs(std::string &path);

// handles non-trivial events
void keydown_handler(SDL_Event &event, int &index, int size);

#endif
