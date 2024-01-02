# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/22 10:18:14 by rel-isma          #+#    #+#              #
#    Updated: 2023/09/23 12:30:29 by rel-isma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCES =  Account.cpp tests.cpp

OBJECTS = $(SOURCES:%.cpp=%.o)

NAME = Account

all: $(NAME)

%.o: %.cpp Account.hpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@printf "\033[0;36mCompiling $<\033[0m\n"

$(NAME): $(OBJECTS) 
	@printf "\033[0;32mLinking...\033[0m\n"
	@$(CXX) $(OBJECTS) -o $(NAME)
	@printf "\033[0;32m$(NAME) compilation completed.\033[0m\n"

clean:
	@printf "\033[0;31mCleaning object files...\033[0m\n"
	@rm -rf $(OBJECTS)
	@printf "\033[0;32mObject files cleaned.\033[0m\n"

fclean: clean
	@printf "\033[0;31mCleaning executable...\033[0m\n"
	@rm -f $(NAME)
	@printf "\033[0;32mExecutable cleaned.\033[0m\n"
	
re: fclean all