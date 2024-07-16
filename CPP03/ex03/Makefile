SRCS = main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp \
		FragTrap.cpp \
		DiamondTrap.cpp \

OBJS = $(SRCS:.cpp=.o)

NAME = ScavTrap

CC = c++

CFLAGS = -std=c++98 -Wall -Werror -Wextra

# colors
GREEN = \033[0;32m
NC = \033[0m
YELLOW = \e[0;93m

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
	@echo "	 			+---------------------+\n \
					|  $(YELLOW)   ScavTrap $(GREEN)[OK]$(NC)   |\n \
					+---------------------+"


.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.cpp=.o}

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re
