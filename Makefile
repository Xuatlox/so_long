.PHONY : all clean fclean re
SRC = so_long.c \
		map.c \
		map2.c \
		ft_strlen.c \
		ft_ardup.c \
		get_next_line.c \
		get_next_line_utils.c
OBJ_DIR = obj/
NAME = so_long
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
CC = cc
MLX = MacroLibX/libmlx.so
CFLAGS = -Wall -Werror -Wextra -g

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) -lSDL2

$(OBJ) : $(SRC)
	cd $(OBJ_DIR) && $(CC) $(CFLAGS)  -c $(addprefix ../, $(SRC))

clean : $(OBJ)
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)
