executable: main.o encoderLib.o
	gcc -o hw1 main.o encoderLib.o -lm

main.o: main.c encoderLib.h
	gcc -c main.c

encoderLib.o: encoderLib.c encoderLib.h
	gcc -c encoderLib.c

clean:
	rm *.o
	rm hw1
