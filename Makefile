CXX = g++-9

CXXFLAGS = -std=c++17 -Wall
LDFLAGS = -L/usr/local/lib -lsdl_wrap -I/usr/local/include

SDLFLAGS = -framework SDL2 -I /Library/Frameworks/SDL2.framework/Headers
SDL2FLAG = -framework SDL2_image -I /Library/Frameworks/SDL2_image.framework/Headers

all: gallery

# create the main application executable
gallery: gallery.o
	$(CXX) $(LDFLAGS) $(SDLFLAGS) $(SDL2FLAGS) -o gallery gallery.o

# create object file for our main gallery class
gallery.o: gallery.cpp gallery.h
	$(CXX) $(CXXFLAGS) -c -o gallery.o gallery.cpp

clean:
	rm gallery gallery.o
