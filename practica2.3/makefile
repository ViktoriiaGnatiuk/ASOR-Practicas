TARGET = $1
CC = gcc
CXX=g++
CFLAGS = -g -Wall 
OBJS = $1.o
SOURCES = $(addsuffix .cc, $(basename $(OBJS)))

all: $(TARGET)

$(TARGET): $(OBJS) 
	$(CXX) $(CFLAGS) -o $(TARGET) $(OBJS)

.c.o: 
	$(CXX) $(CFLAGS) -cc  $< -o $@

clean: 
	-rm -f *.o $(TARGET) 

