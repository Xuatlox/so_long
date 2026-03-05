.PHONY : all clean fclean re bonus
SRC = so_long.c \
		so_long_utils.c \
		map.c \
		map2.c \
		ft_strlen.c \
		check_ber.c \
		ft_ardup.c \
		get_next_line.c \
		get_next_line_utils.c \
		ft_itoa.c
OBJ_DIR = obj/
SRC_BONUS = so_long_bonus.c \
            so_long_utils_bonus.c \
   			so_long_utils2_bonus.c \
   			map.c \
            map2_bonus.c \
            ft_strlen.c \
            check_ber.c \
            ft_ardup.c \
            get_next_line.c \
            get_next_line_utils.c \
            ft_itoa.c
BONUS_OBJ_DIR = bonus_obj/
NAME = so_long
NAME_BONUS = so_long_bonus
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
BONUS_OBJ = $(addprefix $(BONUS_OBJ_DIR), $(SRC_BONUS:.c=.o))
CC = cc
MLX = MacroLibX/libmlx.so
CFLAGS = -Wall -Werror -Wextra -g

all : $(NAME)

$(NAME) : $(MLX) $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) -lSDL2

$(OBJ_DIR) :
	mkdir $(OBJ_DIR)

$(OBJ) : $(SRC)
	cd $(OBJ_DIR) && $(CC) $(CFLAGS)  -c $(addprefix ../, $(SRC))

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(MLX) $(BONUS_OBJ_DIR) $(BONUS_OBJ)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(BONUS_OBJ) $(MLX) -lSDL2

$(BONUS_OBJ_DIR) :
	mkdir $(BONUS_OBJ_DIR)

$(BONUS_OBJ) : $(SRC_BONUS)
	cd $(BONUS_OBJ_DIR) && $(CC) $(CFLAGS) -c $(addprefix ../, $(SRC_BONUS))

$(MLX) :
	git clone https://github.com/seekrs/MacroLibX.git
	cd MacroLibX && make -j

clean :
	rm -rf $(OBJ) $(BONUS_OBJ)

fclean : clean
	rm -rf $(NAME) $(NAME_BONUS)

re : fclean $(NAME)
