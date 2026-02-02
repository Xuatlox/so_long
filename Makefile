.PHONY : all clean fclean re
SRC = so_long.c
OBJ_DIR = obj/
NAME = so_long
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
CC = cc
CFLAGS = -Wall -Werror -Wextra -g

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) -Imlx_linux/libmlx.a $(OBJ)

$(OBJ) : $(SRC)
	cd $(OBJ_DIR) && $(CC) $(CFLAGS) -Imlx_linux/libmlx.a -c $(addprefix ../, $(SRC))

clean : $(OBJ)
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)
