CXX := g++

CXXFLAGS := -std=c++11 -O2 -s -Wall -Wno-switch -Werror

SRCS := agb.cpp error.cpp main.cpp midi.cpp tables.cpp

HEADERS := agb.h error.h main.h midi.h tables.h

.PHONY: all clean

all: mid2agb
	@:

mid2agb: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@ $(LDFLAGS)

clean:
	$(RM) mid2agb mid2agb.exe
