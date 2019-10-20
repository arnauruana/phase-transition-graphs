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
	# ============================ RGG experiments ============================= #
	# -------------------------- Connected components -------------------------- #
	/usr/bin/time sh -c "./graph rgg 10 0:1:0.002 -c 100 > $(OUTDIR)/rgg1-c.csv"
	/usr/bin/time sh -c "./graph rgg 100 0.0:0.3:0.0003 -c 100 > $(OUTDIR)/rgg2-c.csv"
	/usr/bin/time sh -c "./graph rgg 1000 0.0:0.08:0.0008 -c 100 > $(OUTDIR)/rgg3-c.csv"
	# ----------------------- Giant connected component ------------------------ #
	/usr/bin/time sh -s "./graph rgg 10 0:1:0.002 -s 100 > $(OUTDIR)/rgg1-s.csv"
	/usr/bin/time sh -s "./graph rgg 100 0.0:0.3:0.0003 -s 100 > $(OUTDIR)/rgg2-s.csv"
	/usr/bin/time sh -s "./graph rgg 1000 0.0:0.08:0.0008 -s 100 > $(OUTDIR)/rgg3-s.csv"
	# ----------------------------- Complete graph ----------------------------- #
	/usr/bin/time sh -k "./graph rgg 10 0:1:0.002 -k 100 > $(OUTDIR)/rgg1-k.csv"
	/usr/bin/time sh -k "./graph rgg 100 0.0:0.3:0.0003 -k 100 > $(OUTDIR)/rgg2-k.csv"
	/usr/bin/time sh -k "./graph rgg 1000 0.0:0.08:0.0008 -k 100 > $(OUTDIR)/rgg3-k.csv"
	# ----------------------------- Regular graph ------------------------------ #
	/usr/bin/time sh -r "./graph rgg 10 0:1:0.002 -r 100 > $(OUTDIR)/rgg1-r.csv"
	/usr/bin/time sh -r "./graph rgg 100 0.0:0.3:0.0003 -r 100 > $(OUTDIR)/rgg2-r.csv"
	/usr/bin/time sh -r "./graph rgg 1000 0.0:0.08:0.0008 -r 100 > $(OUTDIR)/rgg3-r.csv"

	# ============================ BRG experiments ============================= #
	# -------------------------- Connected components -------------------------- #
	/usr/bin/time sh -c "./graph brg 10 0.0:1:0.001 -c 100 > $(OUTDIR)/brg1-c.csv"
	/usr/bin/time sh -c "./graph brg 100 0.0:0.1:0.0001 -c 100 > $(OUTDIR)/brg2-c.csv"
	/usr/bin/time sh -c "./graph brg 1000 0.0:0.01:0.0001 -c 100 > $(OUTDIR)/brg3-c.csv"
	# ----------------------- Giant connected component ------------------------ #
	/usr/bin/time sh -c "./graph brg 10 0.0:1:0.001 -s 100 > $(OUTDIR)/brg1-s.csv"
	/usr/bin/time sh -c "./graph brg 100 0.0:0.1:0.0001 -s 100 > $(OUTDIR)/brg2-s.csv"
	/usr/bin/time sh -c "./graph brg 1000 0.0:0.01:0.0001 -s 100 > $(OUTDIR)/brg3-s.csv"
	# ----------------------------- Complete graph ----------------------------- #
	/usr/bin/time sh -c "./graph brg 10 0.0:1:0.001 -k 100 > $(OUTDIR)/brg1-k.csv"
	/usr/bin/time sh -c "./graph brg 100 0.0:0.1:0.0001 -k 100 > $(OUTDIR)/brg2-k.csv"
	/usr/bin/time sh -c "./graph brg 1000 0.0:0.01:0.0001 -k 100 > $(OUTDIR)/brg3-k.csv"
	# ----------------------------- Regular graph ------------------------------ #
	/usr/bin/time sh -c "./graph brg 10 0.0:1:0.001 -r 100 > $(OUTDIR)/brg1-r.csv"
	/usr/bin/time sh -c "./graph brg 100 0.0:0.1:0.0001 -r 100 > $(OUTDIR)/brg2-r.csv"
	/usr/bin/time sh -c "./graph brg 1000 0.0:0.01:0.0001 -r 100 > $(OUTDIR)/brg3-r.csv"
	# ========================================================================== #


clean:
	$(RM) $(obj) graph *.png
