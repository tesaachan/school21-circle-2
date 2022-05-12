# DEFINITIONS

NAME			=	push_swap

MAKEFILE		=	Makefile

FLAGS			=	-Wall -Wextra -Werror

HEADER_DIR		=	include/
HEADER_FILES	=	push_swap.h

SRC_DIR			=	src/
SRC_FILES		=	main.c\
					utils.c\
					unsorted_array.c sorted_array.c\
					stack_a.c stack_b.c\
					sort.c\
					instructions.c instructions_both.c\
					cost.c cost_utils.c

FT_DIR			=	libft/
FT_FILES		=	ft_atoi.c ft_split.c\
					ft_lstadd_front.c ft_lstadd_back.c\
					ft_lstnew.c ft_lstsize.c

HEADER			=	$(addprefix $(HEADERS_DIR), $(HEADERS_FILES))
SRC				=	$(addprefix $(SRC_DIR), $(SRC_FILES))
FT				=	$(addprefix $(FT_DIR), $(FT_FILES))

OBJ_M			=	$(SRC:.c=.o)
OBJ_FT			=	$(FT:.c=.o)


# COMMANDS

%.o:			%.c $(HEADER) $(MAKEFILE)
					@gcc ${FLAGS} -c $< -o $@

$(NAME):		$(OBJ_M) $(OBJ_FT)
					@gcc $(OBJ_M) $(OBJ_FT) -o $(NAME)

all:			$(NAME)

clean:
					@rm -rf $(OBJ_M) $(OBJ_FT)				

fclean: 		clean
					@rm -rf $(NAME)

re:				fclean all

.PHONY:		all clean fclean re
