CXX = c++
CXXFlags = -Wall -Wextra -Werror -std=c++98 

NAME = ex03
SRCS = main.cpp  Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

all : $(NAME)
$(NAME) : $(SRCS)
	@echo "\033[33mCompiling [$(NAME)]....\033[0m"
	@$(CXX) $(CXXFlags) $(SRCS) -o $(NAME)
	@echo "\033[32m./$(NAME) is ready.\033[0m"
clean :
	@echo "\033[31mCleaning...\033[0m"
	@rm -f $(NAME)
fclean : clean
re : clean all
.PHONY : all clean fclean re 