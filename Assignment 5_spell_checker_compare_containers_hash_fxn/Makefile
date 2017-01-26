

CC = g++ -std=c++0x

compare-containers: compare.o MyDS.o
	$(CC) compare.o MyDS.o -o compare-containers

compare.o: compare.cpp dictionary.h MyDS.h cputime.h MyHash.h
	$(CC) -c compare.cpp
	
MyDS.o: MyDS.cpp MyDS.h MyHash.h
	$(CC) -c MyDS.cpp

tarfile: 
	tar -cf proj5.tar compare.cpp MyDS.cpp dictionary.h MyHash.h MyDS.h cputime.h result.txt LOG.txt Makefile
        
clean:
	rm -rf compare-containers compare.o MyDS.o proj5.tar
	
kill:
	find ./ -name '*~' | xargs rm

