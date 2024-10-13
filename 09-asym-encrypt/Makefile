PROGRAM_NAME = asym_encrypt

LIBS = -lcrypto -lssl

SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(SOURCES:src/%.cpp=obj/%.o)

all: $(PROGRAM_NAME)

$(PROGRAM_NAME): $(OBJECTS)
	g++ -o $@ $^ $(LIBS)

obj/%.o: src/%.cpp
	@mkdir -p obj
	g++ -c -o $@ $< -g

clean:
	rm -rf $(PROGRAM_NAME) obj
