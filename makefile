.PHONY: all clean

CC = g++
CFLAGS = -std=c++17 -O2 -Wall
OBJS = perceptron.o digitreader.o csvreader.o 

all: DigitRecognition clean

DigitRecognition: main.cpp $(OBJS)
	$(CC) $(CFLAGS) -o $@ $< $(OBJS)

perceptron.o: perceptron.cpp perceptron.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

digitreader.o: digitreader.cpp digitreader.hpp perceptron.o
	$(CC) $(CFLAGS) -c -o $@ $<

csvreader.o: csvreader.cpp csvreader.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm *.o
