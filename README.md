# simple-gallery (WIP)
Simple (command-line) tool to view and navigate through images in a directory using C++ and SDL

## Dependencies:
    * sdl-wrapper
    * SDL 2.0
    * SDL_IMG

## TODO:
    1. Sort image files according to date updated/created
    2. Window size according to image size

## How this should (mainly) work:
    * Run executable in command-line:
        - Run on some path specified by command-line argument
        - BY DEFAULT: run on current directory (on `pwd`)
    * Display one image at a time in a window
        - Size of window / display depends on size of image
        - Sorted according to some option -> date modified/created?
    * Navigation:
        - Use Left/Right arrow keys to navigate between images

## Extra stuff:
    * Display all images in the directory all at once + scrolling + navigation
    * Handle image quality when rendering
