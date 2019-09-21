CC = gcc
CXX = g++

src = $(wildcard *.cc)
obj = $(src:.cc=.o)

LDFLAGS =
CXXFLAGS = 

graph: $(obj)
	$(CXX) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) graph 
