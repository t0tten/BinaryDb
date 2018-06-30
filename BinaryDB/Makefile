CC	= g++

BNAME	= BinaryDb
BDIR	= bin
ODIR	= src/obj
IDIR	= include
SDIR	= src

_DEPS	= Tree.h Item.h StringItem.h IntItem.h DoubleItem.h Record.h
DEPS	= $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ	= Main.o StringItem.o IntItem.o DoubleItem.o Record.o
OBJ	= $(patsubst %,$(SDIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< 

$(BDIR)/$(BNAME): $(OBJ)
	@if [ ! -d $(BDIR) ]; then \
		mkdir $(BDIR); \
	fi
	$(CC) -o $@ $^ 
	@echo " << Make: done >> "
	@echo "Run: make run"
	@echo "Clean: make clean"

.PHONY:	clean

clean:
	@rm -R $(BDIR) $(SDIR)/*.o 2>/dev/null
	@echo " << Clean: done >> "

run:
	@./$(BDIR)/$(BNAME)

