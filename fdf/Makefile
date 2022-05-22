NAME 			=	fdf

MAKEFILE		=	Makefile
CC				=	gcc
FLAGS			=	-Wall -Wextra -Werror

MAN_DIR			=	man/
BONUS_DIR		=	bonus/

HEADER_M		=	fdf.h map.h model.h view.h
SRC_M			=	main.c \
					map.c map_hex_atoi.c\
					model.c model_draw_wf.c model_draw_line.c model_gradient.c \
					view.c view_mrz.c

HEADER_B		=	fdf_bonus.h map_bonus.h model_bonus.h view_bonus.h
SRC_B			=	main_bonus.c \
					map_bonus.c map_hex_atoi_bonus.c\
					model_bonus.c model_draw_wf_bonus.c model_draw_line_bonus.c model_gradient_bonus.c \
					view_bonus.c view_mrz_bonus.c


UTILS_HEADER	= 	utils.h
UTILS			= 	ft_error_msg.c ft_split.c ft.c get_next_line.c ft_atoi.c
UTILS_DIR		= 	utils/

MAN_H			=	$(addprefix $(MAN_DIR), $(HEADER_M))
MAN_SRC			=	$(addprefix $(MAN_DIR), $(SRC_M))

BONUS_H			=	$(addprefix $(BONUS_DIR), $(HEADER_B))
BONUS_SRC		=	$(addprefix $(BONUS_DIR), $(SRC_B))

UTILS_H			= 	$(addprefix $(UTILS_DIR), $(UTILS_HEADER))
UTILS_SRC		= 	$(addprefix $(UTILS_DIR), $(UTILS))

OBJ_M			= 	$(MAN_SRC:.c=.o)
OBJ_B			= 	$(BONUS_SRC:.c=.o)
OBJ_UTILS		= 	$(UTILS_SRC:.c=.o)

MLX_DIR			=	minilibx_macos/


%.o:			%.c $(BONUS_H) $(MAN_H) $(UTILS_H)
					$(CC) $(FLAGS) -c $< -o $@

${MLX}:
				make -C ${MLX_DIR}

$(NAME):		$(OBJ_M) $(OBJ_UTILS)
					$(CC) $(OBJ_M) $(OBJ_UTILS) -L${MLX_DIR} -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all:			${NAME} ${MLX}

bonus:			$(OBJ_B) $(OBJ_UTILS)
					$(CC) $(OBJ_B) $(OBJ_UTILS) -L${MLX_DIR} -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
					@rm -rf $(OBJ_B) $(OBJ_M) $(OBJ_UTILS)
					make -C ${MLX_DIR} clean

fclean:			clean
					@rm -rf $(NAME)

re:				fclean all

.PHONY:			all bonus clean fclean re
