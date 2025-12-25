# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/24 15:47:40 by amtan             #+#    #+#              #
#    Updated: 2025/12/25 17:27:11 by amtan            ###   ########.fr        #
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

FILES_ops   	:= ops_recorder.c
FILES_parse 	:= atoi_strict.c has_duplicates.c parse_args.c rank_values.c  
FILES_sort  	:= 
FILES_stack 	:= 
FILES_utils 	:= sort_int_array.c

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