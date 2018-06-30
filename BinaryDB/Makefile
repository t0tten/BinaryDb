CXX	= g++
CXXFLAGS= -std=c++11

BNAME	= BinaryDb
BDIR	= bin
ODIR	= src/obj
IDIR	= include
SDIR	= src

_DEPS	= Tree.h Item.h StringItem.h IntItem.h DoubleItem.h Record.h Table.h Database.h BinaryDB.h
DEPS	= $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ	= Main.o StringItem.o IntItem.o DoubleItem.o Record.o Table.o Database.o BinaryDB.o
OBJ	= $(patsubst %,$(SDIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CXX) -c -o $@ $<

$(BDIR)/$(BNAME): $(OBJ)
	@if [ ! -d $(BDIR) ]; then \
		mkdir $(BDIR); \
	fi
	$(CXX) -o $@ $^
	@echo " << Make: done >> "
	@echo "Run: make run"
	@echo "Clean: make clean"

.PHONY:	clean

clean:
	@rm -R $(BDIR) $(SDIR)/*.o 2>/dev/null
	@echo " << Clean: done >> "

run:
	@./$(BDIR)/$(BNAME)

