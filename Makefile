CXX = g++-9

CXXFLAGS = -std=c++17 -Wall
LDFLAGS = -L/usr/local/lib -lsdl_wrap -I/usr/local/include

all: gallery

# create the main application executable
gallery: gallery.o
	$(CXX) $(LDFLAGS) -o gallery gallery.o

# create object file for our main gallery class
gallery.o: gallery.cpp gallery.h
	$(CXX) $(CXXFLAGS) -c -o gallery.o gallery.cpp

clean:
	rm gallery gallery.o
