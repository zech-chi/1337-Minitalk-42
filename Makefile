CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

NAMEC = client

NAMES = server

SRC = minitalk_utils.c

OBJ = $(SRC:.c=.o)

SC = client.c

OC = $(SC:.c=.o)

SS = server.c

OS = $(OS:.c=.o)

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) $^ -o $@

$(NAMEC): $(OBJ) $(OC)
	$(CC) $(CFLAGS) $^ -o $@

#$(NAMES): $(OBJ) $(OS)
#	$(CC) $(CFLAGS) $^ -o $@

all: $(NAMEC) #$(NAMES)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAMEC)
	$(RM) $(NAMES)

re: all

.PHONY: all clean fclean re