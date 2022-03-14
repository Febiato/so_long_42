
NAME		= 	so_long

NAME_B		= 	so_long_bonus

MAKEFILE	= 	Makefile

SRC			= 	main.c read_file.c move.c ft_write_steps.c \
				ft_visual.c ft_exit.c check_name.c check_map.c \
				

SRC_BONUS	=	./bonus/main_bonus.c ./bonus/read_file_bonus.c \
				./bonus/move_bonus.c ./bonus/ft_visual_bonus.c \
				./bonus/ft_put_enemy_bonus.c ./bonus/ft_insteps_bonus.c \
				./bonus/ft_exit_bonus.c ./bonus/ft_enemy_bonus.c \
				./bonus/check_name_bonus.c ./bonus/check_map_bonus.c \

OBJS		= ${SRC:.c=.o}

OBJS_BONUS	= ${SRC_BONUS:.c=.o}

D_FILES		= $(patsubst %.c, %.d, $(SRC), $(SRC_BONUS))

HEADER		= so_long.h

MLX			= mlx/libmlx.a

MLB_FLAGS	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o

HEADER_B	= ./bonus/so_long_bonus.h

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

.PHONY		:	all clean fclean re bonus

all			:	${NAME}

%.o 		: %.c ${MAKEFILE}
			$(CC) -Wall -Wextra -Werror -c $< -o $@ -MD

$(NAME)	:	${OBJS}
			$(CC) $(OBJS) $(MLB_FLAGS) $(NAME)

bonus	: 	${OBJS_BONUS}
			$(CC) $(OBJS_BONUS) $(MLB_FLAGS) $(NAME_B)
			
clean		:
	@rm -f ${OBJS} ${OBJS_BONUS} ${D_FILES}

fclean	:	clean
	@${RM} ${NAME} ${NAME_B}

-include $(D_FILES)

re		:	fclean all

