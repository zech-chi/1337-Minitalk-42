NAMEC = client

NAMES = server

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC =	client.c\
		server.c

OBJ = $(SRC:.c=.o)

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -o $^

all: $(NAMEC) $(NAMES)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAMEC)
	$(RM) $(NAMES)

re: all

.PHONY: all clean fclean re