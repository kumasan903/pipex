NAME		= pipex
SRCS		= pipex.c lib.c
OBJS		= $(SRCS:.c=.o)
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
TESTCFLAGS	= -g -fsanitize=address -fsanitize=undefined
ARFLAGS		= rcs

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft/libft.a

clean	:
	$(RM) $(OBJS)
	$(MAKE) clean -C ./libft

clean_local	:
	$(RM) $(OBJS)

fclean	:	clean
	$(RM) $(NAME)
	$(MAKE) fclean -C ./libft

fclean_local	: clean_local
	$(RM) $(NAME)

re		:	fclean_local all

test	: $(NAME)
	./pipex

.PHONY	:	clean fclean clean_local fclean_local re all test
