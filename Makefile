# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/20 18:21:35 by fquist            #+#    #+#              #
#    Updated: 2022/03/17 20:22:05 by fquist           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g

LIBFTDIR	= libs/libft
INCLUDES	= -I./include-I./$(LIBFTDIR)/include
LIBRARIES	= -L./$(LIBFTDIR)/ -lft
################################################################################
# SRCS PUSH_SWAP
SDIR		:= src/*
SRCS		:= 1_stack_utils.c 2_stack_utils2.c 3_find_min_max.c 4_init_struct.c \
			   1_swaps.c 2_pushs.c 3_rotates.c 4_rev_rotates.c mod_atoi.c \
			   parser.c 1_indexing.c 2_ranking.c get_lis.c 1_chunks.c \
			   2_small_chunks_utils.c smart_rotations.c 1_small_sorts.c \
			   2_big_sorts.c 3_big_sort_utils.c 4_insertion_utils.c main.c \
			   frees.c checker.c

ODIR		= obj
OBJS		= $(addprefix $(ODIR)/, $(SRCS:.c=.o))

# COLORS
COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m
UP = "\033[A"
CUT = "\033[K"

# **************************************************************************** #
#	RULES																	   #
# **************************************************************************** #

.PHONY: all
all: $(NAME)

header:
	@printf "$(COM_COLOR)==================== $(OBJ_COLOR)$(NAME)$(COM_COLOR) ====================$(NO_COLOR)\n"

# Linking
.PHONY: $(NAME)
$(NAME): libft header prep $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBRARIES) -lreadline
	@printf $(UP)$(CUT)
	@printf "%-54b %b" "$(OK_COLOR)$(NAME) compiled successfully!" "$(G)[✓]$(X)$(NO_COLOR)\n"


# Compiling
.PHONY: $(ODIR)/%.o
$(ODIR)/%.o: $(SDIR)/%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf $(UP)$(CUT)
	@printf "%-61b %b" "$(COM_COLOR)compiling: $(OBJ_COLOR)$@" "$(OK_COLOR)[✓]$(NO_COLOR)\n"

.PHONY: libft
libft:
ifneq ($(MAKECMDGOALS), $(filter $(MAKECMDGOALS), $(NAME) $(CHECKER)))
	@make -C $(LIBFTDIR) $(MAKECMDGOALS) --silent
else
	@make -C $(LIBFTDIR) --silent
endif

bonus: all

.PHONY: prep
prep:
	@mkdir -p $(ODIR)

.PHONY: clean
clean: libft header
	@$(RM) -r $(ODIR) $(CHECK_ODIR)
	@printf "%-54b %b" "$(ERROR_COLOR)$(NAME) cleaned!" "$(OK_COLOR)[✓]$(NO_COLOR)\n"

.PHONY: fclean
fclean: libft header clean
	@$(RM) $(NAME) $(CHECKER)
	@$(RM) -r src/$(NAME) src/*.dSYM
	@printf "%-54b %b" "$(ERROR_COLOR)$(NAME) fcleaned!" "$(OK_COLOR)[✓]$(NO_COLOR)\n"

.PHONY: re
re: libft fclean all

.PHONY: bonus
bonus: all

# Push_swap_visualizer needed.
mvisual500: all
	@python3 pyviz.py `ruby -e "puts (-249..250).to_a.shuffle.join(' ')"`

visual500:
	@python3 pyviz.py `ruby -e "puts (-249..251).to_a.shuffle.join(' ')"`
	
mvisual100: all
	@python3 pyviz.py `ruby -e "puts (-49..50).to_a.shuffle.join(' ')"`

visual100:
	@python3 pyviz.py `ruby -e "puts (-49..50).to_a.shuffle.join(' ')"`