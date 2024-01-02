# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 15:22:40 by rel-isma          #+#    #+#              #
#    Updated: 2023/11/24 16:29:57 by rel-isma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXX = c++

SOURCES = main.cpp Fixed.cpp
OBJECTS = $(SOURCES:%.cpp=obj/%.o)

NAME = a.out

all: $(NAME)

obj/%.o: %.cpp Fixed.hpp | obj
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
