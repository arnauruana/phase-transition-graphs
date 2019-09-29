#CC = gcc
#CXX = g++
#RM = rm -f

src = $(wildcard *.cpp)
obj = $(src:.cpp=.o)

OUTDIR = ../results
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
	
exp: graph
	$(RM) -r $(OUTDIR)
	mkdir $(OUTDIR)
	/usr/bin/time sh -c "./graph rgg 10 0:1:0.002 -c 100 > $(OUTDIR)/rgg1.csv"
	/usr/bin/time sh -c "./graph rgg 100 0.0:0.3:0.0003 -c 100 > $(OUTDIR)/rgg2.csv"
	/usr/bin/time sh -c "./graph rgg 1000 0.0:0.08:0.0008 -c 100 > $(OUTDIR)/rgg3.csv"
	
	/usr/bin/time sh -c "./graph brg 10 0.0:1:0.001 -c 100 > $(OUTDIR)/brg1.csv"
	/usr/bin/time sh -c "./graph brg 100 0.0:0.1:0.0001 -c 100 > $(OUTDIR)/brg2.csv"
	/usr/bin/time sh -c "./graph brg 1000 0.0:0.01:0.0001 -c 100 > $(OUTDIR)/brg3.csv"
	


clean:
	$(RM) $(obj) graph *.png
