CC = cc
CFLAGS = -Wall -Werror -Wextra 
SRC = main.c
OBJ = $(SRC:.c=.o)
HEAD = lab.h sort.h

all:
	$(CC) $(CFLAGS) -c $(SRC) $(HEAD)
	$(CC) $(CFLAGS) -o project $(OBJ)
	