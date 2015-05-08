# make with make -f BlackBoxGenerator.make

CC=g++
CFLAGS=-c -Wall -O3
OFLAGS = -Wall -O3
LDFLAGS= -Wall
SOURCES=BlackBoxDataGenerator.cpp \
        mathutil.cpp

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=BlackBoxDataGenerator.exe

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
