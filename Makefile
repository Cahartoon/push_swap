# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmartine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/28 16:32:39 by mmartine          #+#    #+#              #
#    Updated: 2018/05/17 23:17:41 by edinguim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: re, clean, fclean, all

CC= gcc

CFLAGS= -Wall -Wextra -Werror

NAME_1= push_swap

NAME_2= checker

LIB= ./libft/libft.a

SRC_FILE= cmd.c\
		  display_pile.c\
		  init.c\
		  init2.c\
		  issort.c\
		  move.c\
		  quick.c\
		  reverse_quick.c\
		  sort_small.c\
		  utils.c\
		  utils2.c

SRC_CHECKER= checker.c

SRC_PUSH= push_swap.c

OBJ= $(SRC_FILE:.c=.o)

OBJ_CHECKER= $(SRC_CHECKER:.c=.o)

OBJ_PUSH= $(SRC_PUSH:.c=.o)

all: $(OBJ) $(OBJ_CHECKER) $(OBJ_PUSH) $(NAME_1) $(NAME_2)

$(NAME_1):
	@echo "Make libft.a"
	@$(MAKE) -C ./libft
	@echo "Make push_swap"
	@$(CC) $(CFLAGS) $(OBJ) $(OBJ_PUSH) $(LIB) -o $(NAME_1)

$(NAME_2): 
	@echo "Make checker"
	@$(CC) $(CFLAGS) $(OBJ) $(OBJ_CHECKER) $(LIB) -o $(NAME_2)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Object files deleted"
	@rm -f $(OBJ) $(OBJ_CHECKER) $(OBJ_PUSH)
	@$(MAKE) -C ./libft clean

fclean: clean
	@echo "Checker and Push_swap deleted"
	@rm -f $(NAME_1) $(NAME_2)
	@$(MAKE) -C ./libft fclean

re: fclean all
