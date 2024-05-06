CXX = g++
CFLAGS = -std=c++98 -Wall -Wextra -Werror
NAME = megaphone

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
	./$(NAME) "shhhhh... I think the students are asleep..."
# SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
	./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
# DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
	./$(NAME)
# * LOUD AND UNBEARABLE FEEDBACK NOISE *

$(OBJS): %.o: %.cpp
	$(CXX) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

