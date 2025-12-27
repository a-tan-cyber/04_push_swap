# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/24 15:47:40 by amtan             #+#    #+#              #
#    Updated: 2025/12/27 20:05:01 by amtan            ###   ########.fr        #
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
FILES_sort  	:= push_swap_run.c rotate_to_top.c sort_chunks.c sort_small.c stack_is_sorted.c
FILES_stack 	:= build_stack_from_vals.c node_new.c stack_clear.c \
					stack_init.c stack_primitives.c stack_push_pop.c
FILES_utils 	:= ctx_init_free.c free_vals_write_error.c sort_int_array.c stack_index_of.c

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

NAME_BONUS		:= checker
OBJDIR_BONUS	:= obj_bonus

FILES_checker	:= checker_main_bonus.c checker_apply_bonus.c
FILES_utils_bonus := sort_int_array.c

# checker needs: parse + stack + utils + stack_is_sorted
SRCS_BONUS		:= $(addprefix $(SRCDIR)/checker/,$(FILES_checker)) \
					$(addprefix $(SRCDIR)/parse/,$(FILES_parse)) \
					$(addprefix $(SRCDIR)/stack/,$(FILES_stack)) \
					$(addprefix $(SRCDIR)/utils/,$(FILES_utils_bonus)) \
					$(SRCDIR)/sort/stack_is_sorted.c

OBJS_BONUS		:= $(SRCS_BONUS:$(SRCDIR)/%.c=$(OBJDIR_BONUS)/%.o)
DEPS_BONUS		:= $(OBJS_BONUS:.o=.d)

bonus			: $(NAME_BONUS)

$(NAME_BONUS)	: $(OBJS_BONUS) $(LIBFT)
					$(CC) $(CFLAGS) $^ -o $@

$(OBJDIR_BONUS)/%.o : $(SRCDIR)/%.c $(HDRS)
					mkdir -p $(@D)
					$(CC) $(CFLAGS) $(CPPFLAGS) -MMD -MP -c $< -o $@

clean_bonus		:
					$(RM) $(OBJS_BONUS) $(DEPS_BONUS)
					$(RMDIR) $(OBJDIR_BONUS)

fclean_bonus	: clean_bonus
					$(RM) $(NAME_BONUS)

re_bonus		: fclean_bonus bonus

-include $(DEPS_BONUS)

.PHONY : all bonus clean fclean re FORCE clean_bonus fclean_bonus re_bonus
