# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 10:37:38 by rel-isma          #+#    #+#              #
#    Updated: 2023/12/06 23:13:13 by rel-isma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXX = c++
CXXHEDAER = Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp
SOURCES = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp
OBJECTS = $(SOURCES:%.cpp=obj/%.o)

NAME = Polymorphism

all: $(NAME)

obj/%.o: %.cpp $(CXXHEDAER) | obj
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@printf "\033[0;36mCompiling $<\033[0m\n"

obj:
	@printf "\033[0;32mCreating obj directory\033[0m\n"
	@mkdir obj

$(NAME): $(OBJECTS)
	@printf "\033[0;31mLinking...\033[0m\n"
	@$(CXX) $(OBJECTS) -o $(NAME)
	@printf "\033[0;32m$(NAME) compilation completed.\033[0m\n"

clean:
	@printf "\033[0;31mCleaning object files...\033[0m\n"
	@rm -rf obj
	@printf "\033[0;32mObject files cleaned.\033[0m\n"

fclean: clean
	@printf "\033[0;31mCleaning executable...\033[0m\n"
	@rm -f $(NAME)
	@printf "\033[0;32mExecutable cleaned.\033[0m\n"

re: fclean all

.PHONY: all clean fclean re
