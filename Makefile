CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

NAMES = server

NAMEC = client

SRC = utils/minitalk_utils.c

SC = mandatory/client.c

SS = mandatory/server.c

OBJ = $(SRC:.c=.o)

OC = $(SC:.c=.o)

OS = $(SS:.c = .o)

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) $^ -o $@

$(NAMES): $(OS) $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(NAMEC): $(OC) $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

all: $(NAMES) $(NAMEC)

clean:
	$(RM) $(OBJ)
	$(RM) $(OS)
	$(RM) $(OC)

fclean: clean
	$(RM) $(NAMES)
	$(RM) $(NAMEC)

re: all

.PHONY: all clean fclean