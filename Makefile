NAME = push_swap

CFLAG = -Wall -Wextra -Werror

RM = rm -f	

AR = ar
ARFLAGS = crs


SRCS =	main.c \
		push_swap.c \
		push_swap_utils.c \
		ft_atoi.c \
		ft_isdigit.c \
		ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c \

all : $(NAME)

$(OBJS) : $(SRCS:.c=.o)

$(NAME) : $(OBJS)

%.o : %c
	gcc $(CFLAG) -c $< -o $@

clean :
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : clean fclean re