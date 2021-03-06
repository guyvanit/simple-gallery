CXX = g++-9

CXXFLAGS = -std=c++17 -Wall -I/usr/local/include
LDFLAGS = -L/usr/local/lib -lsdl_wrap
SDLFLAGS = -framework SDL2 -framework SDL2_image

all: gallery

# create the main application executable
gallery: gallery.o
	$(CXX) $(LDFLAGS) $(SDLFLAGS) -o gallery gallery.o

# create object file for our main gallery class
gallery.o: gallery.cpp gallery.h
	$(CXX) $(CXXFLAGS) -c -o gallery.o gallery.cpp

# ------------- SETUP -------------

# move executable to expected location
install:
	cp gallery /custom/bin

# ----------- CLEAN-UP -----------

clean:
	rm gallery gallery.o
