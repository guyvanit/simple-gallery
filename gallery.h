#ifndef GALLERY
#define GALLERY

#include <filesystem>
#include <string>
#include <vector>

typedef std::vector<std::filesystem::path> PathVector;

// ---- function declarations ----
std::unique_ptr<PathVector> getImgDirs(std::string &path);

#endif
