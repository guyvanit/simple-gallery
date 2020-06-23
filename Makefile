CXX = g++-9

CXXFLAGS = -std=c++17 -Wall -F /Library/Frameworks
LDFLAGS = -framework SDL2 -I /Library/Frameworks/SDL2.framework/Headers
LD2FLAG = -framework SDL2_image -I /Library/Frameworks/SDL2_image.framework/Headers

all: gallery

gallery: gallery.o
	$(CXX) $(LDFLAGS) $(LD2FLAG) -o gallery gallery.o

gallery.o: gallery.cpp gallery.h
	$(CXX) $(CXXFLAGS) -c -o gallery.o gallery.cpp

clean:
	rm gallery gallery.o
