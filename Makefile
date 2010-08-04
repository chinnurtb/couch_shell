MK=make
DIRS=src

all:
	cd $(DIRS); make all

.PHONY: clean

clean:
	cd $(DIRS); make clean
