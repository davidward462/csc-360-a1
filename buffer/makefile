#David Ward
#V00920409
#CSC 360 A1

# variables
COMPILER=gcc
OPTIONS=-g
COMPILE=$(COMPILER) $(OPTIONS)
BUILD=build
PROGRAM=pman
all: program

program: PMan.c $(BUILD)/linkedlist.o
	$(COMPILE) $< $(BUILD)/*.o -o $(PROGRAM) -lreadline

$(BUILD)/linkedlist.o: linkedlist.c linkedlist.h build
	$(COMPILE) -c $< -o $@

args: args.c
	$(COMPILE) args.c -o args

build:
	mkdir -p $(BUILD)

clean:
	rm -rf $(BUILD) program *.bak
