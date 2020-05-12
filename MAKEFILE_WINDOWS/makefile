
# Options de compilation
# CFLAGS = 
CFLAGS = -g -Wall

# nom des librairies a lier
LNAME = -lm

# nom de l executable
EXEC=dm.exe

#liste des fichiers sources (on aurait pu utiliser SRC= $(wildcard *.c)
SRC=  main.c diskfct.c calcul.c

#liste des fichiers objets
OBJ= $(SRC:.c=.o)

# action declenchee par defaut
all: $(EXEC)
    
CC=gcc

# compilation des fichiers sources en fichiers objets
%.o: %.c
	$(CC) $(CFLAGS) -c $^

# compilation de l exectubale a partir des fichier sources
$(EXEC) : $(OBJ)
	$(CC)  -lm -o $@ $^ $(LNAME)
	chmod +x $(EXEC)
	echo compilation terminee

clean:
	rm -rf *.o
	ls
