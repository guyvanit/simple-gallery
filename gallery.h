#ifndef GALLERY
#define GALLERY

// ------- H-REQUIRED INCLUDES -------

#include <filesystem>
#include <string>
#include <vector>

// ------- VARIABLE DECLARATIONS -------

// vector containing path to some file
typedef std::vector<std::filesystem::path> PathVector;

// ------- FUNCTION DECLARATIONS -------

// returns smart pointer to names of all images in path directory
std::unique_ptr<PathVector> getImgDirs(std::string &path);

//  -- SDL functions --

bool init();
bool loadImage();

#endif
