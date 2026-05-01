NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c parsing.c lnklst.c \
       push_a.c push_b.c \
       swap_a.c swap_b.c swap_s.c \
       rotate_a.c rotate_b.c rotate_r.c counter.c adaptive.c\
       reverse_rotate_a.c reverse_rotate_b.c reverse_rotate_r.c algorithm.c \
       simple_short.c utils1.c index.c radix.c sort_small.c chunk.c ft_split.c\
	   

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all