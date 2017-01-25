

CC = g++

Spell: spell_checker.o
	$(CC) spell_checker.o -o Spell

spellchecker.o: spell_checker.cpp dictionary.h LinkedList.h
	$(CC) -c spell_checker.cpp
	
tarfile: 
	tar -cf proj3.tar spell_checker.cpp dictionary.h LinkedList.h LOG.txt Makefile
        
clean:
	rm -rf Spell spell_checker.o proj3.tar
	
kill:
	find ./ -name '*~' | xargs rm

