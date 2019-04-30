plus_minus : bar.o foo.o main.o
	gcc -o plus_minus bar.o foo.o main.o

bar.o : bar.c
	gcc -c -o bar.o bar.c

foo.o : foo.c
	gcc -c -o foo.o foo.c

main.o : main.c
	gcc -c -o main.o main.c

clean :
	rm *.o plus_minus
