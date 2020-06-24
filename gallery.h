#ifndef GALLERY
#define GALLERY

#include <filesystem>

typedef std::vector<std::filesystem::path> PathVector;

// ---- function declarations ----
std::unique_ptr<PathVector> getImgDirs(std::string &path);

#endif
