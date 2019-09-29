CFLAGS = -std=c++11 -Wall

PROGRAM = Megaminx
OBJS = Side.o Mega.o MegaSource.o

all:$(PROGRAM)

$(PROGRAM):$(OBJS)
	g++ -O3 $(OBJS) -o $(PROGRAM)

O3:$(OBJS)
	g++ -O3 $(OBJS) -o $(PROGRAM)

O2:$(OBJS)
	g++ -O2 $(OBJS) -o $(PROGRAM)

O1:$(OBJS)
	g++ -O1 $(OBJS) -o $(PROGRAM)

MegaSource.o: MegaSource.cpp
	g++ -c $(CFLAGS) MegaSource.cpp

Side.o: Side.cpp Side.h
	g++ -c $(CFLAGS) Side.cpp

Mega.o: Mega.cpp Mega.h
	g++ -c $(CFLAGS) Mega.cpp

clean:
	rm -f core $(PROGRAM) $(OBJS)
