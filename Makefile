NAME			=	philo

source			=	main.c \
					init_args.c \
					check_arguments.c \
					ft_atoi.c \
					philo.c \
					timeinterval.c \
					wait_time.c \
					manipulate_threads.c \
					checker.c  \
					print_action.c

HEAD			=	include/philo.h

OBJS			=	${addprefix src/,${source:.c=.o}}

CC				=	gcc

CFLAGS			=	-Wall -Werror -Wextra -g -I -g -I $(HEAD)

.c.o			:
					${CC} ${CFLAGS}  -c $< -o ${<:.c=.o}

$(NAME)			:	${OBJS} ${HEAD}
					${CC} ${CFLAGS} ${LD_FLAGS}  ${OBJS} -o ${NAME} 

all				:	${NAME}

clean			:
					@rm -rf ${OBJS}

fclean			:	clean
					@rm -rf ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re