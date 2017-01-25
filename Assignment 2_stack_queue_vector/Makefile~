all: usestack.exe main.exe

usestack.exe: Vector.o stack.o queue.o 
	g++ ./usestack.cpp -Wall -o ./usestack.exe -g 
main.exe: Vector.o stack.o queue.o 
	g++ ./main.cpp -Wall -o ./main.exe -g
tarfile: 
	tar -cf proj2.tar ./*

clean:
	rm -f *.o *.x *~
