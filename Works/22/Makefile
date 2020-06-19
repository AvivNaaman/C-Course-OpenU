CC = gcc # compiler
CFLAGS = -ansi -Wall -pedantic # gcc flags
EXE_O_DEPS = complex.o mycomp.o input.o # dependencies for executable
# final executable
mycomp: $(EXE_O_DEPS)
	$(CC) -g $(EXE_O_DEPS) $(CFLAGS) -lm -o $@
# complex operations
complex.o: complex.c complex.h
	$(CC) -c complex.c $(CFLAGS) -o $@
# main - depend on all headers as well (for typedefs & constants)
mycomp.o: mycomp.c complex.h input.h mycomp.h
	$(CC) -c mycomp.c $(CFLAGS) -o $@
# input processing
input.o: input.c input.h
	$(CC) -c input.c $(CFLAGS) -o $@
