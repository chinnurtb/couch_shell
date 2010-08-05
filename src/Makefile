# Licensed under the Apache License, Version 2.0 (the "License"); you may not
# use this file except in compliance with the License. You may obtain a copy of
# the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
# License for the specific language governing permissions and limitations under
# the License.

include ../Makefile.head

_HDEPS = cosh.h
HDEPS = $(patsubst %,$(INC)/%,$(_DEPS))

DEPS = main.c

_OBJECTS = main.o
OBJECTS = $(patsubst %,$(OBJ)/%,$(_OBJECTS))

all: $(EXE)/cosh

$(EXE)/cosh: $(OBJECTS)
	-test -d $(EXE) || mkdir $(EXE)
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^

.PHONY: clean

clean:
	\rm -f *~ $(INC)/*~ 
	\rm -f $(OBJ)/*.o 
	\rm -f $(EXE)/cosh
	\rm -f $(EXE)/core

$(OBJ)/%.o: %.c $(HDEPS) $(DEPS)
	-test -d $(OBJ) || mkdir $(OBJ)
	$(CC) $(CFLAGS) -c -o $@ $<

