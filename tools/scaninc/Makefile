CXX = g++

CXXFLAGS = -Wall -std=c++11 -O2

SRCS = scaninc.cpp

.PHONY: clean

scaninc: $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@

clean:
	$(RM) scaninc scaninc.exe
