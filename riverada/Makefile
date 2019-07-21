CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: randomtestresults.out

randomtestresults.out: randomtestcard1.c randomtestcard2.c randomtestcard3.c dominion.c

	echo "Results for running tests: " > randomtestresults.out
	echo "randomtestcard1.c: " >> randomtestresults.out
	gcc -o randomtestcard1 dominion.c rngs.c randomtestcard1.c $(CFLAGS)
	./randomtestcard1 >> randomtestresults.out
	gcov dominion.c -b -f >> randomtestresults.out

	echo "randomtestcard2.c: " >> randomtestresults.out
	gcc -o randomtestcard2 dominion.c rngs.c randomtestcard2.c $(CFLAGS)
	./randomtestcard2 >> randomtestresults.out
	gcov dominion.c -b -f >> randomtestresults.out

	echo "randomtestcard3.c: " >> randomtestresults.out
	gcc -o randomtestcard3 dominion.c rngs.c randomtestcard3.c $(CFLAGS)
	./randomtestcard3 >> randomtestresults.out
	gcov dominion.c -b -f >> randomtestresults.out
	
clean:
	rm randomtestresults.out

cleanall:
	rm randomtestresults.out randomtestcard1 randomtestcard2 randomtestcard3 *.gcda *.gcno *.gcov

