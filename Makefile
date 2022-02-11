
#Color:

RED		= \033[0;31m
DEFAULT	= \033[0;39m
PINK	= \033[1;35m
BLUE	= \033[1;34m

#Make_file

NAME	= push_swap
LIBFT	= libft/libft.a
CHECKER = checker
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf	
PRINTF 	= printf

SRCS =	main.c \
		sorting_fcts.c \
		push_swap_utils.c \
		lst_options.c \
		ssorting.c \
		stack_utils.c 

SRCS_CH =	dir_checker/checker_utils.c \
			dir_checker/apply_rules_utils.c \
			dir_checker/checker.c \
			dir_checker/get_next_line.c \
			dir_checker/get_next_line_utils.c \
			dir_checker/rules.c \
			sorting_fcts.c \
			push_swap_utils.c \
			lst_options.c \
			ssorting.c \
			stack_utils.c 

OBJS = $(SRCS:.c=.o)
OBJS_CH = $(SRCS_CH:.c=.o)

#Compiling Stage:

all : $(NAME)

$(NAME) : do_libft $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@
	@$(PRINTF) "\r%100s\r$(BLUE)$(NAME) is up to date!$(DEFAULT)\n"

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(PRINTF) "\rCompiling $(BLUE)$<$(DEFAULT)..."

do_libft : 
	@make all -C libft/

bonus : $(CHECKER)

$(CHECKER) : do_libft $(OBJS_CH)
	@$(CC) $(CFLAGS) $(OBJS_CH) $(LIBFT) -o $@
	@$(PRINTF) "\r%100s\r$(BLUE)$(CHECKER) is up to date!$(DEFAULT)\n"
clean :
	@$(PRINTF) "$(PINK)Cleaning $(NAME) ... $(DEFAULT)\n"
	@if [ -d "libft" ]; then \
		make clean -C libft; \
	fi
	@$(RM) $(OBJS)
	@$(RM) $(OBJS_CH)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(CHECKER)
	@if [ -d "libft" ]; then \
		$(RM) $(LIBFT); \
	fi 
	@$(PRINTF) "$(RED) $(NAME) removed successfully. $(DEFAULT)\n"
	@if [ -d "libft" ]; then \
		$(PRINTF) "$(RED) $(LIBFT) removed successfully. $(DEFAULT)\n"; \
	fi 

re : fclean 
	@make all

.PHONY : all do_libft clean fclean re