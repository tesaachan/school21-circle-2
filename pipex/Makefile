# DEFINITIONS

NAME			=	pipex

MAKEFILE		=	Makefile

FLAGS			=	-Wall -Wextra -Werror

HEADER_DIR		=	include/
HEADER_FILES	=	pipex.h pipex_bonus.h

SRC_DIR			=	src/
SRC_FILES		=	ft_split.c ft_strdup.c ft_strjoin.c ft_strncmp.c\
					ft_strlen.c pipex.c pipex_utils.c
		
BONUS_DIR		=	bonus/
BONUS_FILES		=	ft_split.c ft_strdup.c ft_strjoin.c ft_strncmp.c\
					ft_strlen.c get_next_line.c pipex_files.c pipex_free.c pipex_pipes.c\
					pipex_bonus.c pipex_utils_bonus.c

HEADER			=	$(addprefix $(HEADERS_DIR), $(HEADERS_FILES))
SRC				=	$(addprefix $(SRC_DIR), $(SRC_FILES))
BONUS			=	$(addprefix $(BONUS_DIR), $(BONUS_FILES))

OBJ_M			=	$(SRC:.c=.o)

OBJ_B			=	$(BONUS:.c=.o)


# COMMANDS

%.o:			%.c $(HEADER) $(MAKEFILE)
					@gcc ${FLAGS} -c $< -o $@

$(NAME):		$(OBJ_M)
					@gcc $(OBJ_M) -o $(NAME)

all:			$(NAME)

bonus:			$(OBJ_B)
					@gcc $(OBJ_B) -o $(NAME)

clean:
					@rm -rf $(OBJ_M)
					@rm -rf $(OBJ_B)					

fclean: 		clean
					@rm -rf $(NAME)

re:				fclean all

.PHONY:		all clean fclean bonus re
