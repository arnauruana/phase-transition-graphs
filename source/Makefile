#CC = gcc
#CXX = g++
#RM = rm -f

src = $(wildcard *.cc)
obj = $(src:.cc=.o)

LDFLAGS =
CXXFLAGS = -std=c++11 -Wall

graph: $(obj)
	$(CXX) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	$(RM) $(obj) graph 
