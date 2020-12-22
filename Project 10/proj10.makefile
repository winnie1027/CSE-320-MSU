proj10: proj10.support.o proj10.driver.o
	gcc proj10.support.o proj10.driver.o -o proj10

proj10.support.o: proj10.support.s
	gcc -c proj10.support.s

proj10.driver.o: proj10.driver.c project10.support.h
	gcc -Wall -c proj10.driver.c