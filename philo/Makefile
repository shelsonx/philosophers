SRCS_FILES	=	actions.c exit.c lib.c
SRCS_FILES	+=	init.c main.c philo.c time.c utils.c
SRCS_FILES	+=	meals.c info.c forks.c eating_process.c

SRCS_FILES_BONUS	= 	

SRCS_DIR			= src

SRCS				= $(SRCS_FILES)

OBJS				= $(SRCS:.c=.o)

RM 					= rm -f

CC					= gcc

CFLAGS 				= -Wall -Wextra -Werror -g
LDFLAGS				= -lpthread

NAME				= philo
NAME_BONUS			= 

all:				$(NAME)


$(NAME):			$(OBJS)
					$(CC)  $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)
					
clean:
					$(RM) $(OBJS)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re
