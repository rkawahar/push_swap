SRCS = axis.c command_parts.c command1.c command2.c compression.c create_lst.c ft_over6.c \
ft_split.c push_swap_utils.c push_swap.c sort_core.c sort_three.c sort_under3.c sort_under6.c 
NAME = push_swap
CC = cc
CFLGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)

%.o : %.c
	$(CC) $(CFLGS) -c $^ -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 