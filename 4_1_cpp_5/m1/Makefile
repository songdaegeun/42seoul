CXX = g++
CFLAGS = -std=c++98 -Wall -Wextra -Werror
NAME = phonebook

# LIBFT =
# HEADER = 
# HEADERS = $(addprefix include/, $(HEADER))

SRC = $(NAME).cpp
SRCS = $(SRC)
# SRCS = $(addprefix src/, $(SRC))
OBJS = $(SRCS:.cpp=.o)

.PHONY: clean, fclean, re, all

all: $(NAME)
	
$(NAME): $(OBJS)
	$(CXX) $(CFLAGS) -o $@ $(OBJS)
	./$(NAME)

$(OBJS): %.o: %.cpp
	$(CXX) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

