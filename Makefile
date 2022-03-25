# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skathale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/19 16:43:11 by skathale          #+#    #+#              #
#    Updated: 2022/02/19 16:43:33 by skathale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME =		push_swap

NAMEB =		checker

SRC	=		main.c program.c io_processing/put_nbr.c io_processing/put_str.c\
			linked_list/list_methods.c linked_list/node_methods.c operations/operations_utils.c\
			io_processing/print_list.c insertion_sort/insertion_sort.c\
			linked_list/list_utils.c qsort/quick_sort.c simple_sort/triple_sort.c simple_sort/five_sort.c \
			io_processing/ft_split.c io_processing/string_processing.c io_processing/parser.c\

SRC_BONUS =	bonus_main.c program.c io_processing/put_nbr.c io_processing/put_str.c\
			linked_list/list_methods.c linked_list/node_methods.c operations/operations_bonus_utils.c\
			operations/push_operations.c operations/rotate_operations.c operations/swap_operations.c\
			linked_list/list_utils.c operations/execute_command.c operations/reverse_rotate_operations.c\
			io_processing/ft_split.c io_processing/string_processing.c io_processing/parser.c \
			gnl/get_next_line.c gnl/get_next_line_utils.c io_processing/print_list.c\

OBJ		= 	$(SRC:.c=.o)

OBJ_BONUS = ${SRC_BONUS:.c=.o}

CC		=	gcc
CFLAGS	=	-Wextra -Werror -Wall

.PHONY	:all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)

bonus: $(NAMEB)

$(NAMEB): $(OBJ_BONUS)
	$(CC) $(CFLAGS) -o $(NAMEB) $(SRC_BONUS)

clean	:
	@rm -f $(OBJ_BONUS) $(OBJ)

fclean	:	clean
	@rm -f $(NAME)

re		:	fclean all
