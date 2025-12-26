# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/24 15:47:40 by amtan             #+#    #+#              #
#    Updated: 2025/12/26 20:21:30 by amtan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        	:= push_swap

CC          	:= cc
CFLAGS      	:= -Wall -Wextra -Werror
CPPFLAGS    	:= -Iinclude -Ilibft

RM          	:= rm -f
RMDIR       	:= rm -rf

SRCDIR      	:= src
OBJDIR      	:= obj

LIBFTDIR    	:= libft
LIBFT       	:= $(LIBFTDIR)/libft.a

HDRS        	:= include/push_swap.h

SRC_MAIN 		:= main.c
DIRS 			:= ops parse sort stack utils

FILES_ops   	:= op_push.c op_rev_rotate.c op_rotate.c op_swap.c\
					ops_recorder.c
FILES_parse 	:= atoi_strict.c has_duplicates.c parse_args.c rank_values.c  
FILES_sort  	:= push_swap_run.c
FILES_stack 	:= build_stack_from_vals.c node_new.c stack_clear.c \
					stack_init.c stack_primitives.c stack_push_pop.c
FILES_utils 	:= ctx_init_free.c free_vals_write_error.c sort_int_array.c

SRCS 			:= $(addprefix $(SRCDIR)/, $(SRC_MAIN)) \
					$(foreach d,$(DIRS),$(addprefix $(SRCDIR)/$(d)/,$(FILES_$(d))))

OBJS        	:= $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
DEPS        	:= $(OBJS:.o=.d)

all				: $(NAME)

$(NAME)			: $(OBJS) $(LIBFT)
					$(CC) $(CFLAGS) $^ -o $@

$(LIBFT)		: FORCE
					$(MAKE) -C $(LIBFTDIR)

FORCE			:

$(OBJDIR)/%.o	: $(SRCDIR)/%.c $(HDRS)
					mkdir -p $(@D)
					$(CC) $(CFLAGS) $(CPPFLAGS) -MMD -MP -c $< -o $@

clean			:
					$(RM) $(OBJS) $(DEPS)
					$(RMDIR) $(OBJDIR)
					$(MAKE) -C $(LIBFTDIR) clean

fclean			: clean
					$(RM) $(NAME)
					$(MAKE) -C $(LIBFTDIR) fclean

re				: fclean all

-include $(DEPS)

.PHONY			: all clean fclean re FORCE