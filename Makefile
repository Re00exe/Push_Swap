NAME = push_swap

CC = gcc
CFLAG = -Wall -Wextra -Werror

RM = rm -f	

AR = ar
ARFLAGS = crs


SRCS =	push_swap.c \
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
		
		

OBJS = push_swap.o \
		push_swap_utils.o \
		ft_atoi.o \
		ft_isdigit.o \
		ft_lstadd_back.o \
		ft_lstadd_front.o \
		ft_lstclear.o \
		ft_lstiter.o \
		ft_lstlast.o \
		ft_lstmap.o \
		ft_lstnew.o \
		ft_lstsize.o \



all : $(NAME)

$(OBJS) : $(SRCS:.c=.o)

$(NAME) : $(OBJS)

%.o : %c
	$(CC) $(CFLAG) -c $< -o $@

clean :
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : clean fclean re