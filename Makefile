COMPILE=gcc
RM=rm -f
CFLAGS=-g
LDFLAGS=-g
LDLIBS=
SRCS=main.c core.c debug.c instr.c
OBJS=$(subst .c,.o,$(SRCS))
TARGET=ocho

all: $(OBJS)
	$(COMPILE) $(LDFLAGS) -o $(TARGET) $(OBJS) $(LDLIBS)

clean:
	$(RM) $(OBJS) $(TARGET)
