#variabili

CC = gcc
CFLAGS = -Wall 
#OBJ = 

#Regole

#fase di linking
esame: compito.o liste.o tipo.o 
	$(CC) $(CFLAGS) -o esame $^

#fase di generazione file oggetto
compito.o: compito.c liste.h tipo.h
	$(CC) $(CFLAGS) -c $<

liste.o: liste.c liste.h 
	$(CC) $(CFLAGS) -c $<

tipo.o: tipo.c tipo.h
	$(CC) $(CFLAGS) -c $<


clean:
	del -f *.o *.exe *.out


.PHONY: clean