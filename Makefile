INCDIR = include/ardealte
SRCDIR = src/ardealte
_OBJDIR = obj
OBJDIR := $(_OBJDIR)/ardealte
BINDIR = bin

MKDIR_P = mkdir -p

LFLAGS = -Wall
CFLAGS = -Wall -c -O0 --std=c++11 -g -I$(shell pwd)/include
CXX = clang++
COMPILE = $(CXX) $(CFLAGS)
LINK = $(CXX) $(LFLAGS)

_OBJS = tile.o puzzle.o entry.o dictionary.o main.o
OBJS = $(patsubst %, $(OBJDIR)/%,$(_OBJS))

$(OBJDIR)/%.o: $(SRCDIR)/%.cc $(INCDIR)/%.h
	$(OBJDST)
	$(COMPILE) -c -o $@ $<

all: ardealte

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	$(MKDIR_P) $(OBJDIR)

$(BINDIR):
	$(MKDIR_P) $(BINDIR)

ardealte: $(OBJS) | $(BINDIR)
	$(LINK) -o $(BINDIR)/$@ $^

.PHONY: clean

clean:
	rm -rf $(_OBJDIR) $(BINDIR)
