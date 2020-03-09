# Read me before using the tests in this directory
_In order to run these tests, you might need to change some *.c* files:_
1. Make sure your `match.c` file *does not* contain `main()` method.
2. Make sure your method names are correct: compare then to the names at the `tester.h` file. Also make sure that the parameters order is correct.

## Compiling & Running the tests
1. Copy this folder content to the same folder/directory as your other files (such as .c/.h/makefile).
2. Run the command: `make -f tester_makefile`. It'll creare an executable names tester.
3. Run from the terminal the tester, using `./tester`.

### If you get any compilation error, check you *removed your main* and the signatures are correct, in the correct files
### In this tester: make sure there is no `main()` in match.c, which also contains the method `match(char pattern[], char text[])`. Check your parameter order.
