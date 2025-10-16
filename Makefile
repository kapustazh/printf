NAME = libftprintf.a
CC = cc
RM = rm -f
AR = ar

SRCS = printf.c utils1.c utils2.c
OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all