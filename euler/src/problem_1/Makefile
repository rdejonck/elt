CFLAGS = -Wall -Werror
#CFLAGS += -g
PROGS = naive calculated
SRCS = benchmark.cc

BINDIR = bin

PROGOBJS = $(addsuffix .o, $(PROGS))
OBJS = $(SRCS:.cc=.o)
PROGBINS = $(addprefix $(BINDIR)/, $(PROGS))

.PHONY: all clean
all: $(PROGBINS)

clean:
	rm -f $(PROGBINS) $(PROGOBJS) $(OBJS)

$(PROGBINS): $(PROGOBJS) $(OBJS)
	mkdir -p $(BINDIR)
	$(CXX) $(notdir $@).o $(OBJS) $(LDFLAGS) -o $@

$(OBJS) $(PROGOBJS): Makefile
