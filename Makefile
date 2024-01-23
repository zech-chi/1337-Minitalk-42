NAMEC = client

NAMES = server

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = minitalk_utils.c

OBJ = $(SRC:.c=.o)

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -o $^

$(NAMEC): $(OBJ)
	$(CC) $(CFLAGS) $^ client.c -o $@

$(NAMES): $(OBJ)
	$(CC) $(CFLAGS) $^ server.c -o $@

all: $(NAMEC) $(NAMES)

client: $(NAMEC)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAMEC)
	$(RM) $(NAMES)

re: all

.PHONY: all clean fclean re