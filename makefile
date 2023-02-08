#David Ward
#V00920409
#CSC 360 A1

args: args.o
	gcc -o args args.o

args.o: args.c
	gcc -c args.c

clean:
	rm args.o
