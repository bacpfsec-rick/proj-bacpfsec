CC=g++ -std=c++11
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=apfsec.cc
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=Apfsec
LIBS = 

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE):$(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LIBS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *o *~ $(EXECUTABLE)
