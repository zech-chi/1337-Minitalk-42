CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SNAME = server

CNAME = client

SBNAME = server_bonus

CBNAME = client_bonus

SS = mandatory/server.c

SC = mandatory/client.c

SBS = bonus/server_bonus.c

SBC = bonus/client_bonus.c

SUTILS = utils/minitalk_utils.c

OS = $(SS:.c=.o)

OC = $(SC:.c=.o)

OBS = $(SBS:.c=.o)

OBC = $(SBC:.c=.o)

OUTILS = $(SUTILS:.c=.o)

all: $(SNAME) $(CNAME)

bonus: $(SBNAME) $(CBNAME)

$(CNAME): $(OC) $(OUTILS) 
	$(CC) $(CFLAGS) $^ -o $@

$(SNAME): $(OS) $(OUTILS) 
	$(CC) $(CFLAGS) $^ -o $@

$(SBNAME): $(OBS) $(OUTILS)
	$(CC) $(CFLAGS) $^ -o $@

$(CBNAME): $(OBC) $(OUTILS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OUTILS)
	$(RM) $(OS)
	$(RM) $(OC)
	$(RM) $(OBS)
	$(RM) $(OBC)

fclean: clean
	$(RM) $(SNAME)
	$(RM) $(CNAME)
	$(RM) $(SBNAME)
	$(RM) $(CBNAME)

re: all

.PHONY: all clean fclean re bonus