CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: testmeresults.out

testmeresults.out: testme.c 

	@echo "Writing to file testmeresults.out."
	@echo "Results for running tests: " > testmeresults.out
	@echo "testme.c: " >> testmeresults.out
	@echo "Compiling testme.c source file."
	@gcc -o testme testme.c $(CFLAGS)
	@echo "Executing tests and writing results to test results file."
	@./testme >> testmeresults.out
	@gcov testme.c -b -f >> testmeresults.out
	@echo "Tests complete. View results in testmeresults.out."

clean:
	rm testmeresults.out 

cleanall:
	rm testmeresults.out testme *.gcda *.gcno