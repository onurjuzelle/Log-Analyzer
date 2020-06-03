CCOPTS=-Wall -std=c++11 -O3

all: log

log: hashtable.o main.cpp
	g++ $(CCOPTS) -o $@ $^

obj/hashtable.o: hashtable.cpp hashtable.h
	g++ $(CCOPTS) -o $@ -c hashtable.cpp

clear:
	rm obj/* log
