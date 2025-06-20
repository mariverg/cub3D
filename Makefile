MAINILES = main cggame render
SCREENFILES = c3dscreen/mlxbuilder c3dscreen/imgtools c3dscreen/colorbuilder c3dscreen/mappainter c3dscreen/3dpainter  c3dscreen/texture_loader c3dscreen/texture_utils
ITEMFILES = c3ditems/cgitems c3ditems/mapmaker c3ditems/playermaker c3ditems/raymaker
FILES = $(MAINILES) $(SCREENFILES) $(ITEMFILES)
OFILES = $(addsuffix .o, $(FILES))
FLAGS = 
FLAGS2 = -Wall -Wextra -Werror
COMP = gcc
NAME = a.out

MLX_DIR = minilibx-linux
LIBFT_DIR = libft
MLX = $(MLX_DIR)/libmlx.a
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -Iminilibx-linux -Ic3dscreen -Ic3ditems -Ilibft
LIBRARIES = -Llibft -lft -Lminilibx-linux -lmlx -lX11 -lXext -lm


all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OFILES)
	$(COMP) -o $(NAME) $(OFILES) $(LIBRARIES)

%.o: %.c
	$(COMP) $(FLAGS) -g $(INCLUDES) -o $@ -c $<

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(LIBFT_DIR) bonus

clean:
	rm -f $(OFILES)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.phony: all clean fclean re


val: $(MLX) $(OFILES)
	$(COMP) -o $(NAME) $(OFILES) $(LIBRARIES)

memtest:
	valgrind --leak-check=full ./$(NAME)

fulltest:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)