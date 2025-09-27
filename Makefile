NAME = libftprintf.a
CC = cc
RM = rm -f

SRCS = main.c func1.c func2.c

CFLAGS = -Wall -Wextra -Werror
CFILES = $(SRCS)
OBJ = $(CFILES:.c=.o)
# BONUS_OBJ = $(BONUS_SRCS:.c=.o)

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) rcs $(NAME) $(OBJ)

# bonus: $(OBJ) $(BONUS_OBJ)
# 	$(AR) rcs $(NAME) $(OBJ) $(BONUS_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all