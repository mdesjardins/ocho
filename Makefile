COMPILE=gcc
RM=rm -f
CFLAGS=-g
LDFLAGS=-g -lncurses -lpanel -lmenu
LDLIBS=
SRCS=main.c core.c debug.c instr.c term.c
OBJS=$(subst .c,.o,$(SRCS))
TARGET=ocho

all: $(OBJS)
	$(COMPILE) $(LDFLAGS) -o $(TARGET) $(OBJS) $(LDLIBS)

clean:
	$(RM) $(OBJS) $(TARGET)
