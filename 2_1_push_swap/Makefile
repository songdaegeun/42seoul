CC=	cc
CFLAGS=	-Wall -Wextra -Werror

NAME = push_swap
BONUS_NAME = checker
SRCDIR = src
HEADERDIR = include
SRC = push_swap.c parse.c deque.c deque2.c instruction.c util.c util2.c optimization.c greedy.c greedy_cost.c greedy_push.c
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
BONUS_SRC = deque_bonus.c deque2_bonus.c instruction_bonus.c parse_bonus.c push_swap_bonus.c util_bonus.c util2_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c
BONUS_SRCS = $(addprefix $(SRCDIR)/, $(BONUS_SRC))
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
HEADER= push_swap.h
HEADERS = $(addprefix $(HEADERDIR)/, $(HEADER))
BONUS_HEADER = push_swap_bonus.h get_next_line_bonus.h
BONUS_HEADERS = $(addprefix $(HEADERDIR)/, $(BONUS_HEADER))

.PHONY: clean, fclean, re, all, bonus

all: $(NAME)
bonus : $(BONUS_NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJS): %.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -o $@ -c $<

$(BONUS_OBJS): %.o: %.c $(BONUS_HEADERS)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS);\
	rm -f $(BONUS_OBJS);\

fclean: clean
	rm -f $(NAME);\
	rm -f $(BONUS_NAME);\

re: fclean all
