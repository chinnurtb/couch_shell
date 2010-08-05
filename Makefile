include Makefile.head

DIRS := src

all:
	cd $(DIRS); $(MAKE) all

.PHONY: clean

clean:
	\rm -f *~
	cd $(DIRS); $(MAKE) clean
