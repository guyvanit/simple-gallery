CXX = g++-9
WDIR = wrappers

CXXFLAGS = -std=c++17 -Wall -F /Library/Frameworks
LDFLAGS = -framework SDL2 -I /Library/Frameworks/SDL2.framework/Headers
LD2FLAG = -framework SDL2_image -I /Library/Frameworks/SDL2_image.framework/Headers

all: gallery

gallery: gallery.o $(WDIR)/sdl_window.o
	$(CXX) $(LDFLAGS) $(LD2FLAG) -o gallery gallery.o $(WDIR)/sdl_window.o

# create object file for our main gallery class -> contains main()
gallery.o: gallery.cpp gallery.h $(WDIR)/sdl_window.h
	$(CXX) $(CXXFLAGS) -c -o gallery.o gallery.cpp

# create object file for wrapper class
sdl_win.o: $(WDIR)/sdl_window.cpp $(WDIR)/sdl_window.h
	$(CXX) $(CXXFLAGS) -c -o $(WDIR)/sdl_window.o $(WDIR)/sdl_window.cpp

# create object file for exceptions class
sdl_exs.o: $(WDIR)/sdl_exceptions.cpp $(WDIR)/sdl_exceptions.h
	$(CXX) $(CXXFLAGS) -c -o $(WDIR)/sdl_exs.o $(WDIR)/sdl_exceptions.cpp

clean:
	rm gallery gallery.o $(WDIR)/sdl_window.o
