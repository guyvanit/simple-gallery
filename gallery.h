#ifndef GALLERY
#define GALLERY

// ------- H-REQUIRED INCLUDES -------

#include <filesystem>
#include <string>
#include <vector>

// ------- VARIABLE DECLARATIONS -------

typedef std::vector<std::filesystem::path> PathVector;

// ------- FUNCTION DECLARATIONS -------

std::unique_ptr<PathVector> getImgDirs(std::string &path);

bool init();
bool loadImage();

#endif
