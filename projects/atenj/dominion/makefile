CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: unittestresults.out

runalltests: unittestresults.out cardtestresults.out randomtestresults.out

unittestresults.out: unittest1.c unittest2.c unittest3.c unittest4.c unittest5.c dominion.c

	echo "Results for running tests: " > unittestresults.out
	echo "unittest1.c: " >> unittestresults.out
	gcc -o unittest1 dominion.c rngs.c unittest1.c $(CFLAGS)
	./unittest1 >> unittestresults.out
	gcov dominion.c -b -f >> unittestresults.out

	echo "unittest2.c: " >> unittestresults.out
	gcc -o unittest2 dominion.c rngs.c unittest2.c $(CFLAGS)
	./unittest2 >> unittestresults.out
	gcov dominion.c -b -f >> unittestresults.out

	echo "unittest3.c: " >> unittestresults.out
	gcc -o unittest3 dominion.c rngs.c unittest3.c $(CFLAGS)
	./unittest3 >> unittestresults.out
	gcov dominion.c -b -f >> unittestresults.out

	echo "unittest4.c: " >> unittestresults.out
	gcc -o unittest4 dominion.c rngs.c unittest4.c $(CFLAGS)
	./unittest4 >> unittestresults.out
	gcov dominion.c -b -f >> unittestresults.out

	echo "unittest5.c: " >> unittestresults.out
	gcc -o unittest5 dominion.c rngs.c unittest5.c $(CFLAGS)
	./unittest5 >> unittestresults.out
	gcov dominion.c -b -f >> unittestresults.out

cardtestresults.out: cardtest1.c cardtest2.c cardtest3.c cardtest4.c cardtest5.c dominion.c

	echo "Results for running tests: " > cardtestresults.out
	echo "cardtest1.c: " >> cardtestresults.out
	gcc -o cardtest1 dominion.c rngs.c cardtest1.c $(CFLAGS)
	./cardtest1 >> cardtestresults.out
	gcov dominion.c -b -f >> cardtestresults.out

	echo "cardtest2.c: " >> cardtestresults.out
	gcc -o cardtest2 dominion.c rngs.c cardtest2.c $(CFLAGS)
	./cardtest2 >> cardtestresults.out
	gcov dominion.c -b -f >> cardtestresults.out

	echo "cardtest3.c: " >> cardtestresults.out
	gcc -o cardtest3 dominion.c rngs.c cardtest3.c $(CFLAGS)
	./cardtest3 >> cardtestresults.out
	gcov dominion.c -b -f >> cardtestresults.out

	echo "cardtest4.c: " >> cardtestresults.out
	gcc -o cardtest4 dominion.c rngs.c cardtest4.c $(CFLAGS)
	./cardtest4 >> cardtestresults.out
	gcov dominion.c -b -f >> cardtestresults.out

	echo "cardtest5.c: " >> cardtestresults.out
	gcc -o cardtest5 dominion.c rngs.c cardtest5.c $(CFLAGS)
	./cardtest5 >> cardtestresults.out
	gcov dominion.c -b -f >> cardtestresults.out

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
	rm unittestresults.out cardtestresults.out randomtestresults.out

cleanall:
	rm unittestresults.out unittest1 unittest3 unittest2 unittest4 unittest5 *.gcda *.gcno *.gcov

cleanallcard:
	rm cardtestresults.out cardtest1 cardtest2 cardtest3 cardtest4 cardtest5 *.gcda *.gcno *.gcov

cleanallrandom:
	rm randomtestresults.out randomtestcard1 randomtestcard2 randomtestcard3 *.gcda *.gcno *.gcov

cleanalltests:
	rm unittestresults.out unittest1 unittest3 unittest2 unittest4 unittest5 cardtestresults.out cardtest1 cardtest2 cardtest3 cardtest4 cardtest5 randomtestresults.out randomtestcard1 randomtestcard2 randomtestcard3 *.gcda *.gcno *.gcov
