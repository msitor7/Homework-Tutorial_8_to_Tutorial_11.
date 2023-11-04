CXX := g++
CXXWARNINGS := -Wall -Wextra -Werror
CXXOPT := -O3
CXXSTD := -std=c++17
INCLUDES := -I include -I ./dependencies/external/include
LIBRARY_DIRS := -L ./dependencies/external/lib -L ./dependencies/external/lib64
LIBRARIES := -l Clara  
CXXFLAGS := $(CXXWARNINGS) $(CXXSTD) $(CXXOPT) $(INCLUDES)
LDFLAGS := $(LIBRARY_DIRS)

.PHONY: all clean

all: main

main: main.cxx src/Example.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS) $(LIBRARIES)

src/%.o: src/%.cxx
	$(CXX) $(CXXFLAGS) $^ -c -o $@

clean:
	rm -v src/*.o main
