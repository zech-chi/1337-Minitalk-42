CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SNAME = server

CNAME = client

SS = mandatory/server.c

SC = mandatory/client.c

SUTILS = utils/minitalk_utils.c

OS = $(SS:.c=.o)

OC = $(SC:.c=.o)

OUTILS = $(SUTILS:.c=.o)

$(CNAME): $(OUTILS) $(OC)
	$(CC) $(CFLAGS) $^ -o $@

$(SNAME): $(OUTILS) $(OS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(SNAME) $(CNAME)

clean:
	$(RM) $(OUTILS)
	$(RM) $(OS)
	$(RM) $(OC)

fclean: clean
	$(RM) $(SNAME)
	$(RM) $(CNAME)

re: all

.PHONY: all clean fclean re