CFLAGS = -I /home/lib2720/allegro5/include/
LIBDIR = /home/lib2720/allegro5/lib/
LNFLAGS = -lallegro -lallegro_primitives -lcppunit -ldl
OBJECTS1 = Date.o TestDate.o
#OBJECTS2 = test2.o

#all:   test1 test2

TestDate: $(OBJECTS1)
	g++ -std=c++0x -L $(LIBDIR) -o $@ $^ $(LNFLAGS)
	rm -rf *o *~

test2: $(OBJECTS2)
	g++ -std=c++0x -L $(LIBDIR) -o $@ $^ $(LNFLAGS) 

%.o : %.cc
	g++ -std=c++0x $(CFLAGS) -c $^

clean:
	rm -rf *o *~
	rm TestDate
