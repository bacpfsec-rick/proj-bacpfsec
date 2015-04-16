RCFLAGS = -I /home/lib2720/allegro5/include/
LIBDIR = /home/lib2720/allegro5/lib/
LNFLAGS = -lallegro -lallegro_primitives -lcppunit -ldl
OBJECTS1 = Date.o TestDate.o
OBJECTS2 = Date.o State.o TestState.o
OBJECTS3 = Date.o State.o Task.o TestTask.o
OBJECTS4 = Date.o Task.o State.o BfcPrototype.o TestBfcPrototype.o
OBJECTS5 = Date.o Task.o State.o BfcPrototype.o BfcTUI.o TestBfcTUI.o
OBJECTS6 = Date.o Task.o State.o TimelineVer.o MenuDetail.o BfcPrototype.o BfcTUI.o BfcTerminal.o BfcTRI.o
OBJECTS7 = Date.o Task.o State.o TimelineHor.o MenuSimple.o BfcPrototype.o BfcTUI.o BfcTerminal.o BfcTRII.o

#all:   TestDate TestState TestTask TestBfcPrototype TestBfcTUI BfcTR
all: BfcTRI BfcTRII

TestDate: $(OBJECTS1)
	g++ -std=c++0x -L $(LIBDIR) -o $@ $^ $(LNFLAGS)

TestState: $(OBJECTS2)
	g++ -std=c++0x -L $(LIBDIR) -o $@ $^ $(LNFLAGS) 

TestTask: $(OBJECTS3)
	g++ -std=c++0x -L $(LIBDIR) -o $@ $^ $(LNFLAGS) 

TestBfcPrototype: $(OBJECTS4)
	g++ -std=c++0x -L $(LIBDIR) -o $@ $^ $(LNFLAGS) 

TestBfcTUI: $(OBJECTS5)
	g++ -std=c++0x -L $(LIBDIR) -o $@ $^ $(LNFLAGS)

BfcTRI: $(OBJECTS6)
	g++ -std=c++0x -L $(LIBDIR) -o $@ $^ $(LNFLAGS)  

BfcTRII: $(OBJECTS7)
	g++ -std=c++0x -L $(LIBDIR) -o $@ $^ $(LNFLAGS)  
	rm -rf *o *~

%.o : %.cc
	g++ -std=c++0x $(CFLAGS) -c $^

clean:
	rm -rf *o *~
#	rm TestDate
#	rm TestState
#	rm TestTask
#	rm TestBfcPrototype
#	rm TestBfcTUI
	rm BfcTRI
	rm BfcTRII
