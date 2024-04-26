SRCS = main.cpp \

OBJS = $(SRCS:.cpp=.o)

NAME = brain

CC = c++

CFLAGS = -std=c++98 -Wall -Werror -Wextra

# colors
GREEN = \033[0;32m
NC = \033[0m
YELLOW = \e[0;93m

$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(NAME)
	@echo "	 			+---------------------+\n \
					|  $(YELLOW)    Brain $(GREEN)[OK]$(NC)     |\n \
					+---------------------+"

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re