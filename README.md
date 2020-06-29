# simple-gallery (WIP)
Simple (command-line) tool to view and navigate through images in a directory using C++ and SDL

## PLAN:
 - Run executable in command line <br/>
 NOTE: lets try to focus on running in current direct first
 - Fetch all image files in current directory
 - Display the images with navigation:
      - Display individual image -> arrow keys to navigate
      - Display all images in a square matrix of images (?)

EXTRA: implement as command line tool to run anywhere?

## TODO:
    0. Wrapper Classes for SDL -> RAII to ensure proper clean-up
        - SDL + SDL_IMG initalisation wrapper
        - <s>SDL_Window wrapper</s>
        - SDL_Renderer wrapper
        - SDL_Texture wrapper?
    1. Get image to display on a window
    2. Sort image files according to date updated/created
    3. Window size according to image size
    4. Render ~10 images at a time -> or some other handling of multiple renderings
    5. Navigation of image displays

## PROGRESS:
- Run tool in specified directory by running in command-line: <br/>
    `./gallery <directory_path>`
