FILES = main mlxbuilder colorbuilder pixelputer
OFILES = $(addsuffix .o, $(FILES))
FLAGS = 
FLAGS2 = -Wall -Wextra -Werror
COMP = gcc
NAME = a.out

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
LIBRARIES = -Lminilibx-linux -lmlx -lX11 -lXext -lm


all: $(NAME)

$(NAME): $(MLX) $(OFILES)
	$(COMP) -o $(NAME) $(OFILES) $(LIBRARIES)

%.o: %.c
	$(COMP) $(FLAGS) -I$(MLX_DIR) -o $@ -c $<

$(MLX):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -f $(OFILES)
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.phony: all clean fclean re