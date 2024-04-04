# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/06 15:53:15 by kbrener-          #+#    #+#              #
#    Updated: 2024/04/04 10:45:41 by kbrener-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME	= push_swap
BONUS	= checker

# Compiler options
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g #-fsanitize=address

# Libft
LIBFT_PATH = ./libft/
LIBFT_LIB = $(LIBFT_PATH)libft.a

# program files
SRC		= 	src/push_swap.c \
			src/push.c \
			src/rotate.c \
			src/swap.c \
			src/reverse_rotate.c \
			src/cheapest.c \
			src/cheapest_utils.c \
			src/cheapest_utils_2.c \
			src/check.c \
			src/init.c \
			src/clean.c \
			src/execute.c \
			src/lst.c \
			src/main.c \


SRC_BONUS	=	src/push.c \
				src/rotate.c \
				src/swap.c \
				src/reverse_rotate.c \
				src/lst.c \
				src/check.c \
				src/init.c \
				src/clean.c \
				bonus/checker.c \

OBJ		= $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

# Includes
INCLUDES = 	-I ./includes/\
			-I ./libft/\

all : $(LIBFT_LIB) $(NAME)

# Compiling Libft
%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(LIBFT_LIB):
	@make -sC $(LIBFT_PATH)

# Compiling PUSH_SWAP
$(NAME): $(OBJ) $(LIBFT_LIB)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) -o $(NAME) -g

# Compiling BONUS
bonus: $(OBJ_BONUS) $(LIBFT_LIB)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT_LIB) -o $(BONUS) -g

clean:
	@echo "les fichiers ont ete supprimes"
	@make clean -sC $(LIBFT_PATH)
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_BONUS)


fclean: clean
	@echo "les fichers ont ete supprimes"
	@make fclean -sC $(LIBFT_PATH)
	@rm -rf $(LIBFT_LIB) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
