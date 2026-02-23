NAME = Bsp
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJS = $(SRC:.cpp=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
