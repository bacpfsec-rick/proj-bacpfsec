CFLAGS = -I /home/lib2720/allegro5/include/
LIBDIR = /home/lib2720/allegro5/lib/
LNFLAGS = -lallegro -lallegro_primitives -lcppunit -ldl
OBJECTS1 = Date.o TestDate.o
OBJECTS2 = Date.o State.o TestState.o

all:   TestDate TestState
#all: TestState

TestDate: $(OBJECTS1)
	g++ -std=c++0x -L $(LIBDIR) -o $@ $^ $(LNFLAGS)

TestState: $(OBJECTS2)
	g++ -std=c++0x -L $(LIBDIR) -o $@ $^ $(LNFLAGS) 
	rm -rf *o *~

%.o : %.cc
	g++ -std=c++0x $(CFLAGS) -c $^

clean:
	rm -rf *o *~
	rm TestDate
	rm TestState
