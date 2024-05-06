CC=	cc
CFLAGS=	-Wall -Wextra -Werror

NAME= libftprintf.a
LIBFT = ./libft/libft.a
SRCDIR = srcs
HEADERDIR = includes
SRC= ft_printf.c ft_res_print.c ft_str_process.c ft_convert_base2nbr.c ft_convert_num.c ft_res_s.c ft_printf_syntax.c ft_convert_util.c ft_convert_util_2.c
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(SRCS:.c=.o)
HEADER= libft.h ft_printf.h ft_res_print.h ft_str_process.h ft_convert_base2nbr.h ft_convert_num.h ft_res_s.h ft_printf_syntax.h ft_convert_util.h ft_convert_util_2.h
HEADERS = $(addprefix $(HEADERDIR)/, $(HEADER))

.PHONY: clean, fclean, re, all

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME);\
	ar rsc $@ $(OBJS)

bonus : all

$(LIBFT):
	$(MAKE) -C ./libft

$(OBJS): %.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS);\
	$(MAKE) -C ./libft clean

fclean: clean
	rm -f $(NAME);\
	$(MAKE) -C ./libft fclean

re: fclean all
