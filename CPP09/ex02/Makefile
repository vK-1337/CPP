SRCS = main.cpp \
			PmergeMe.cpp \

OBJS = $(SRCS:.cpp=.o)

NAME = PmergeMe

CC = c++

CFLAGS = -std=c++98 -Wall -Werror -Wextra -g3

# colors
GREEN = \033[0;32m
NC = \033[0m
YELLOW = \e[0;93m

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "	 		+---------------------+\n \
				|$(YELLOW)    PmergeMe $(GREEN) [OK]   $(NC)|\n \
				+---------------------+"


.cpp.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.cpp=.o}

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re
