SRCS = 	main.cpp \
		Bureaucrat.cpp \
		AForm.cpp \
		PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp \
		ShrubberyCreationForm.cpp \
		Intern.cpp \

OBJS = $(SRCS:.cpp=.o)

NAME = bureaucrat

CC = c++

CFLAGS = -std=c++98 -Wall -Werror -Wextra

# colors
GREEN = \033[0;32m
NC = \033[0m
YELLOW = \e[0;93m

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
	@echo "	 			+---------------------+\n \
					|$(YELLOW)Bureaucrat ex03 $(GREEN) [OK]$(NC)|\n \
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
