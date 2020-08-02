# simple-gallery
Simple (command-line) tool to view and navigate through images in a directory using C++ and SDL

## Dependencies:
    * sdl-wrapper
    * SDL 2.0
    * SDL_IMG

## Building:
    1. Set up dependencies:
        * Install sdl-wrapper using its makefile
        * Set up SDL2.0 and SDL_IMG frameworks (install to /Library/Frameworks/)
    2. Build the executable by running: `make`
    3. Run executable by: `./gallery <path_to_img_directory>`
    4. Setup by running: `make install`
    5. Add installed path to path variable (by default: custom/bin)

## How this should (mainly) work:
    * Run executable in command-line:
        - Run on some path specified by command-line argument
        - BY DEFAULT: run on current directory (on `pwd`)
    * Display one image at a time in a window
        - Size of window / display depends on size of image
        - Sorted according to some option -> date modified/created?
    * Navigation:
        - Use Left/Right arrow keys to navigate between images

***

## TODO:
    1. Sort image files according to date updated/created

## Extra stuff:
    * Display all images in the directory all at once + scrolling + navigation
    * Handle image quality when rendering
