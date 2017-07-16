INCDIR = include/ardealte
SRCDIR = src/ardealte
_OBJDIR = obj
OBJDIR := $(_OBJDIR)/ardealte

MKDIR_P = mkdir -p

LFLAGS = -Wall
CFLAGS = -Wall -c -O0 --std=c++11 -g
CXX = clang++
COMPILE = $(CXX) $(CFLAGS)
LINK = $(CXX) $(LFLAGS)

_OBJS = tile.o puzzle.o main.o
OBJS = $(patsubst %, $(OBJDIR)/%,$(_OBJS))

$(OBJDIR)/%.o: $(SRCDIR)/%.cc $(INCDIR)/%.h
	$(OBJDST)
	$(COMPILE) -c -o $@ $<

all: ardealte

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	$(MKDIR_P) $(OBJDIR)

ardealte: $(OBJS)
	$(LINK) -o $@ $^

.PHONY: clean

clean:
	rm -rf $(_OBJDIR)
