SRCDIR := source
RESDIR := results

RM := rm -vfr


.PHONY: graph test exp clean distclean
graph:
	$(MAKE) -C $(SRCDIR)
	cp $(SRCDIR)/$@ .

test:
	$(MAKE) -C $(SRCDIR) test

exp:
	$(MAKE) -C $(SRCDIR) exp

clean:
	$(MAKE) -C $(SRCDIR) clean

distclean: clean
	$(RM) graph *.png $(RESDIR)
