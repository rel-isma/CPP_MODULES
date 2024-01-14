# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/13 10:53:22 by rel-isma          #+#    #+#              #
#    Updated: 2024/01/13 10:55:03 by rel-isma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXX = c++
CXXHEDAER = Base.hpp identify_functions.hpp derived_classes.hpp Base.cpp 
SOURCES = main.cpp identify_functions.cpp 
OBJECTS = $(SOURCES:%.cpp=obj/%.o)

NAME = Identify

all: $(NAME)

obj/%.o: %.cpp | obj
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