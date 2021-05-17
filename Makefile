# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgalaup <fgalaup@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/05 14:25:53 by fgalaup           #+#    #+#              #
#    Updated: 2021/05/12 16:15:19 by fgalaup          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# Project vars
SORTER_NAME		= push_swap
CHECKER_NAME	= checker

SRCS_COMMON		=		./Sources/_Common/Stack/stack.c \
						./Sources/_Common/Stack/stack_is_sort.c \
						./Sources/_Common/Stack/stack_show.c \
						./Sources/_Common/Instruction/Type/swap_first_a_b.c \
						./Sources/_Common/Instruction/Type/swap_first_a.c \
						./Sources/_Common/Instruction/Type/swap_first_b.c \
						./Sources/_Common/Instruction/Type/pop_b_push_a.c \
						./Sources/_Common/Instruction/Type/pop_a_push_b.c \
						./Sources/_Common/Instruction/Type/rotate_a_b.c \
						./Sources/_Common/Instruction/Type/rotate_a.c \
						./Sources/_Common/Instruction/Type/rotate_b.c \
						./Sources/_Common/Instruction/Type/reverse_rotate_a_b.c \
						./Sources/_Common/Instruction/Type/reverse_rotate_a.c \
						./Sources/_Common/Instruction/Type/reverse_rotate_b.c \
						./Sources/_Common/Instruction/instruction.c \
						./Sources/_Common/Utilities/error.c

SRCS_SORTER		=		./Sources/Sorter/sorter.c\
						./Sources/Sorter/generic_sorter.c \
						./Sources/Sorter/small_stack_sorter.c

SRCS_CHECKER	=		./Sources/Checker/checker.c

HEADER_DIR		=		./Sources

HEADER			=		$(HEADER_DIR)/common_stack.h \
						$(HEADER_DIR)/common_instruction.h \
						$(HEADER_DIR)/common_error.h \
						$(HEADER_DIR)/sorter.h \
						$(HEADER_DIR)/checker.h

# Library

LIBFT_DIR		=		Library/Libft
LIBFT_HEADER	=		$(LIBFT_DIR)
LIBFT			=		$(LIBFT_DIR)/libft.a

# Workings vars
CC				=		clang
CFLAGS			=		-Wall -Wextra -Werror -g3 -fsanitize=address -fsanitize=undefined
CMLXFLAGS		=		

RM				= rm -f
OBJS_COMMON		= $(SRCS_COMMON:.c=.o)
OBJS_SORTER		= $(SRCS_SORTER:.c=.o)
OBJS_CHECKER	= $(SRCS_CHECKER:.c=.o)

all: common_code $(SORTER_NAME) $(CHECKER_NAME)
bonus: common_code $(SORTER_NAME) $(CHECKER_NAME)


common_code: libft $(OBJS_COMMON)

$(SORTER_NAME): libft $(OBJS_SORTER) $(HEADER)
		$(CC) $(CFLAGS) $(LIBFT) $(CMLXFLAGS) $(OBJS_SORTER) $(OBJS_COMMON) -o $(SORTER_NAME)

$(CHECKER_NAME): libft $(OBJS_CHECKER) $(HEADER)
		$(CC) $(CFLAGS) $(LIBFT) $(CMLXFLAGS) $(OBJS_CHECKER) $(OBJS_COMMON) -o $(CHECKER_NAME)


libft:
		$(MAKE) -C $(LIBFT_DIR) all

norminette:
		$(MAKE) -C $(LIBFT_DIR) norminette
		norminette $(SRCS_COMMON) $(SRCS_SORTER) $(SRCS_CHECKER) $(HEADER)

%.o: %.c $(HEADER)
		$(CC) -g3 $(CFLAGS) -I $(LIBFT_HEADER) -I $(HEADER_DIR) -c $< -o $@

clean:
		$(RM) $(OBJS_COMMON) $(OBJS_SORTER) $(OBJS_CHECKER)
		$(MAKE) -C $(LIBFT_DIR) fclean

fclean: clean
		$(RM) $(SORTER_NAME) $(CHECKER_NAME)
		$(MAKE) -C $(LIBFT_DIR) fclean

re:	fclean all

.PHONY:			all bonus common_code re clean fclean libft