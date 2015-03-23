CFLAGS = -I /home/lib2720/allegro5/include/
LIBDIR = /home/lib2720/allegro5/lib/
LNFLAGS = -lallegro -lallegro_primitives
OBJECTS1 = test1.o
OBJECTS2 = test2.o

all:   test1 test2

test1: $(OBJECTS1)
	g++ -std=c++0x -L $(LIBDIR) -o $@ $^ $(LNFLAGS) 

test2: $(OBJECTS2)
	g++ -std=c++0x -L $(LIBDIR) -o $@ $^ $(LNFLAGS) 

%.o : %.cc
	g++ -std=c++0x $(CFLAGS) -c $^

clean:
	rm -rf *o *~
