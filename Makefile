CXX = g++-9

CXXFLAGS = -std=c++17 -Wall -F /Library/Frameworks
LDFLAGS = -framework SDL2 -I /Library/Frameworks/SDL2.framework/Headers
LD2FLAG = -framework SDL2_image -I /Library/Frameworks/SDL2_image.framework/Headers

all: gallery

# create the main application executable
gallery: gallery.o
	$(CXX) -o gallery gallery.o

# create object file for our main gallery class
gallery.o: gallery.cpp gallery.h
	$(CXX) $(CXXFLAGS) -c -o gallery.o gallery.cpp

clean:
	rm gallery gallery.o
