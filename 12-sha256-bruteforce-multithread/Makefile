PROGRAM_NAME = main

CC = g++
CFLAGS = -Wall -Wextra
LIBS = -lssl -lcrypto

SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(SOURCES:src/%.cpp=obj/%.o)

all: $(PROGRAM_NAME)

$(PROGRAM_NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

obj/%.o: src/%.cpp
	@mkdir -p obj
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(PROGRAM_NAME) obj
