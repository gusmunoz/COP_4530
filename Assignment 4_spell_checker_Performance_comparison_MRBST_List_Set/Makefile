

CC = g++

compare-containers: compare.o
	$(CC) compare.o -o compare-containers

compare.o: compare.cpp dictionary.h MRBST.h cputime.h cputime.c cputime.o
	$(CC) -c compare.cpp
	
test.o: test.cpp MRBST.h 
	$(CC) -c test.cpp

tarfile: 
	tar -cf proj4.tar compare.cpp test.cpp dictionary.h MRBST.h cputime.h cputime.c cputime.o result.txt LOG.txt Makefile
        
clean:
	rm -rf compare-containers compare.o proj4.tar
	
kill:
	find ./ -name '*~' | xargs rm

