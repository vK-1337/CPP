SRCS = main.cpp \

OBJS = $(SRCS:.c=.o)

NAME = #INSERT NAME OF .a HERE


CFLAGS = -Wall -Werror -Wextra

# colors
GREEN = \033[0;32m
NC = \033[0m
YELLOW = \e[0;93m

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
	@echo "	 			+---------------------+\n \
		|  $(YELLOW)  #INSERT_PROGRAM_NAME_HERE $(GREEN)[OK]$(NC)   |\n \
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