#ifndef GALLERY
#define GALLERY

#include <filesystem>
#include <string>
#include <vector>

typedef std::vector<std::filesystem::path> PathVector;

// ---- GLOBAL VARIABLES ----

SDL_Window* g_Window;
SDL_Renderer* g_Renderer;

// ---- function declarations ----

std::unique_ptr<PathVector> getImgDirs(std::string &path);

bool init();
bool loadImage();

#endif
