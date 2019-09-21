#CC = gcc
#CXX = g++
#RM = rm -f

src = $(wildcard *.cpp)
obj = $(src:.cpp=.o)

LDFLAGS =
CXXFLAGS = -std=c++11 -Wall

graph: $(obj)
	$(CXX) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	$(RM) $(obj) graph 
