SRCS = 	main.cpp \
		AMateria.cpp \
		Character.cpp \
		Cure.cpp \
		Ice.cpp \
		MateriaSource.cpp \


OBJS = $(SRCS:.cpp=.o)

NAME = materia

CC = c++

CFLAGS = -std=c++98 -Wall -Werror -Wextra -g3

# colors
GREEN = \033[0;32m
NC = \033[0m
YELLOW = \e[0;93m

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "	 			+---------------------+\n \
					|  $(YELLOW)   Materia  $(GREEN)[OK]$(NC)   |\n \
					+---------------------+"


.c.o:
	$(CC) -c $< -o ${<:.c=.o}

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re