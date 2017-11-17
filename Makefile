CC = gcc
CFLAGS = -Wall -g
OBJECTS = main.o affichageGrille.o manipulationGrille.o jeuPuissance4.o

puissance4 : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o puissance4
	rm -f *.o

%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean :
	rm -rf puissance4 *.dSYM