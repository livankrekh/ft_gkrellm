#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/11 19:22:38 by oposhiva          #+#    #+#              #
#    Updated: 2017/11/11 19:22:38 by oposhiva         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_gkrellm

SOURCE = main.cpp \
		Host.class.cpp \
		IMonitorModule.class.cpp \
		Date.class.cpp \
		System.class.cpp \
		Network.class.cpp \
		IMonitorDisplay.class.cpp \
		IMonitorNcurses.class.cpp \
		RAM.cpp \
		CPU.cpp \


OBJECTS = $(SOURCE:.cpp=.o)

CC = clang++
FL = -Wall -Wextra -Werror

all: $(NAME) done

$(NAME): $(OBJECTS)
	@$(CC) $(FL) $(SOURCE) -o $(NAME) -lncurses

%.o: %.cpp
	@$(CC) $(FL) -c $< -o $@

clean:
	@rm -f $(OBJECTS)
	@echo "\033[;33m[ It's clean ]\033[33;0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[;31m[ Deleted ]\033[33;0m"

re: fclean all

done:
	@echo "\033[;32m[ Well done ]\033[33;0m"