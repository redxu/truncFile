CC 		= gcc
CFLAGS 	= -O2 -g -Wall
SRC		= trunc.c test.c

all : truncFile

truncFile : $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o truncFile

clean:
	$(RM) truncFile