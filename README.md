# simple-gallery (WIP)
Simple (command-line) tool to view and navigate through images in a directory using C++ and SDL

## TODO:
    1. Manage window/image size to be displayed correctly
    2. Sort image files according to date updated/created
    3. Window size according to image size
    4. Render ~10 images at a time -> or some other handling of multiple renderings
    5. Navigation of image displays

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
