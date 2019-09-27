#CC = gcc
#CXX = g++
#RM = rm -f

src = $(wildcard *.cpp)
obj = $(src:.cpp=.o)

LDFLAGS =
CXXFLAGS = -std=c++11 -Wall

graph: $(obj)
	$(CXX) -o $@ $^ $(LDFLAGS)


.PHONY: clean debug go 
go: graph
	./graph
	
run: graph
	./graph

test: graph
	./graph test

clean:
	$(RM) $(obj) graph *.png
