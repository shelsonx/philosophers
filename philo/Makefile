SRCS_FILES	=	actions.c exit.c lib.c
SRCS_FILES	+=	init.c main.c philo.c time.c utils.c
SRCS_FILES	+=	meals.c info.c forks.c eating_process.c

SRCS_FILES_BONUS	= 	

SRCS_DIR			= src

SRCS_DIR_BONUS		= src_bonus

SRCS				= $(SRCS_FILES)

SRCS_BONUS			= $(SRCS_FILES_BONUS)

OBJS				= $(SRCS:.c=.o)

OBJS_BONUS			= $(SRCS_BONUS:.c=.o)

RM 					= rm -f

CC					= gcc

CFLAGS 				= -Wall -Wextra -Werror -g
LDFLAGS				= -pthread

NAME				= philo
NAME_BONUS			= 

all:				$(NAME)

bonus:				$(NAME_BONUS)

$(NAME):			$(OBJS)
					$(CC)  $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

$(NAME_BONUS):		$(OBJS_BONUS)
					$(CC)  $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)
					
clean:
					$(RM) $(OBJS)
					$(RM) $(OBJS_BONUS)

fclean:				clean
					$(RM) $(NAME)
					$(RM) $(NAME_BONUS)

re:					fclean all

.PHONY:				all clean fclean re bonus
