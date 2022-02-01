
#Color:

GREEN	= \033[0;32m
DEFAULT	= \033[0;39m
PINK	= \033[1;35m
BLUE	= \033[1;34m

#Make_file

NAME	= push_swap
LIBFT	= libft/libft.a
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

OBJS = $(SRCS:.c=.o)

#Compiling Stage:

all : $(NAME)

$(NAME) : do_libft $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@
	@$(PRINTF) "\r%100s\r$(GREEN)$(NAME) is up to date!$(DEFAULT)\n"

%.o : %.c
	@$(CC) $(CFLAG) -c $< -o $@
	@$(PRINTF) "\rCompiling $(BLUE)$<$(DEFAULT)..."

do_libft:
	@if [! -d "libft"]; then \
		git clone  ; \
	fi
	@make all -C libft/ 

clean:
	@$(PRINTF) "$(PINK)Cleaning $(NAME) ... $(DEFAULT)\n"
	@if [ -d "libft" ]; then \
		make clean -C libft; \
	fi
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)
	@if [ -d "libft" ]; then \
		$(RM) $(LIBFT); \
	fi 
	@$(PRINTF) "$(PINK) $(NAME) removed successfully. $(DEFAULT)\n"
	@if [ -d "libft" ]; then \
		$(PRINTF) "$(PINK) $(LIBFT) removed successfully. $(DEFAULT)\n"; \
	fi 

re : fclean 
	@make all

.PHONY : all do_libft clean fclean re