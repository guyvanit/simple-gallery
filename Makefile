CXX = g++-9
WDIR = wrappers

CXXFLAGS = -std=c++17 -Wall -F /Library/Frameworks
LDFLAGS = -framework SDL2 -I /Library/Frameworks/SDL2.framework/Headers
LD2FLAG = -framework SDL2_image -I /Library/Frameworks/SDL2_image.framework/Headers

all: gallery

gallery: gallery.o $(WDIR)/sdl_wrap.o
	$(CXX) $(LDFLAGS) $(LD2FLAG) -o gallery gallery.o $(WDIR)/sdl_wrap.o

gallery.o: gallery.cpp gallery.h $(WDIR)/sdl_wrap.h
	$(CXX) $(CXXFLAGS) -c -o gallery.o gallery.cpp

# create object file for wrapper class
sdl_wrap.o: $(WDIR)/sdl_wrap.cpp $(WDIR)/sdl_wrap.h
	$(CXX) $(CXXFLAGS) -c -o $(WDIR)/sdl_wrap.o $(WDIR)/sdl_wrap.cpp

clean:
	rm gallery gallery.o $(WDIR)/sdl_wrap.o
