CXX := g++

CXXFLAGS := -Wall -std=c++11 -O2

SRCS := json11.cpp mapjson.cpp

HEADERS := mapjson.h

.PHONY: clean

mapjson: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@ $(LDFLAGS)

clean:
	$(RM) mapjson mapjson.exe
