# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 09:45:16 by rel-isma          #+#    #+#              #
#    Updated: 2023/10/08 13:14:44 by rel-isma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

SOURCES =   main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJECTS = $(SOURCES:%.cpp=obj/%.o)

NAME = attack

all: $(NAME)

obj/%.o: %.cpp HumanA.hpp HumanB.hpp HumanB.hpp | obj
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@printf "\033[0;36mCompiling $<\033[0m\n"

obj:
	@mkdir obj
$(NAME): $(OBJECTS) 
	@printf "\033[0;32mLinking...\033[0m\n"
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