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
	./graph brg 100 0.0:0.1:0.001 -c 32 > $(OUTDIR)/k-brg-100-00-10-00100.csv
	./graph rgg 100 0.0:0.2:0.002 -c 32 > $(OUTDIR)/k-rgg-100-00-20-00200.csv
	
	./graph brg 100 0.0:0.1:0.0001 -c 100 > $(OUTDIR)/c-brg-100-00-10-00100.csv
	./graph rgg 100 0.0:0.2:0.0002 -c 100 > $(OUTDIR)/c-rgg-100-00-20-00200.csv

clean:
	$(RM) $(obj) graph *.png
