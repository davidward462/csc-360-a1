#David Ward
#V00920409
#CSC 360 A1

all: pman args inf

pman: PMan.o linkedlist.o helper.o commands.o
	gcc -o pman  PMan.o linkedlist.o helper.o commands.o -lreadline

PMan.o: PMan.c linkedlist.h helper.h commands.h
	gcc -c PMan.c 

linkedlist.o: linkedlist.c linkedlist.h
	gcc -c linkedlist.c

commands.o: commands.c commands.h linkedlist.h helper.h
	gcc -c commands.c

helper.o: helper.c helper.h
	gcc -c helper.c

args: args.o
	gcc -o args args.o
	
args.o: args.c
	gcc -c args.c

inf: inf.o
	gcc -o inf inf.o

inf.o: inf.c
	gcc -c inf.c

clean:
	rm args.o inf.o linkedlist.o PMan.o helper.o commands.o
