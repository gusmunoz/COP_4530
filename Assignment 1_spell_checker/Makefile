

CC = g++

main: spell_checker.o
	$(CC) spell_checker.o -o main

spellchecker.o: spell_checker.cpp dictionary.h
	$(CC) -c spell_checker.cpp
	
tarfile: 
	tar -cf proj1.tar spell_checker.cpp dictionary.h LOG.txt Makefile
        
clean:
	rm -rf main spell_checker.o proj1.tar
	
kill:
	find ./ -name '*~' | xargs rm

