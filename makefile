NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = main.c parsing.c lnklst.c utils1.c \
	push_a.c push_b.c \
	swap_a.c swap_b.c swap_s.c \
	rotate_a.c rotate_b.c rotate_r.c \
	reverse_rotate_a.c reverse_rotate_b.c reverse_rotate_r.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re