# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 02:01:10 by hlabouit          #+#    #+#              #
#    Updated: 2023/04/09 17:58:52 by hlabouit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	push_swap
SRCS =	$(addprefix instructions/, push_to_stack.c reverse_rotate_stack.c rotate_stack.c swap_stack.c) \
		check_input.c parsing.c linked_lists.c sort_3_numbers.c sort_5_numbers.c sort_100_numbers.c \
		sort_500_numbers.c useful_functions.c push_swap.c lightweight_memory.c
		
SRCS_BONUS = $(addprefix get_next_line/, get_next_line_utils.c get_next_line.c) \
			 $(addprefix instructions/, push_to_stack.c reverse_rotate_stack.c rotate_stack.c swap_stack.c) \
			 check_input.c bonus.c parsing.c linked_lists.c lightweight_memory.c
		
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
CC =  cc
CFLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C libft
	$(CC) $(CFLAGS)  $(OBJS) libft/libft.a -o $(NAME)

bonus: $(OBJS_BONUS) push_swap.h
	$(MAKE) -C libft
	$(CC) $(CFLAGS)  $(OBJS_BONUS) libft/libft.a -o checker

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	$(MAKE) clean -C libft
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(NAME)
	rm -f checker

re: fclean all

.PHONY: all clean fclean re