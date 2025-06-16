#ifndef CUB3D
# define CUB3D

# include "libft.h" 
# include "cgscreen.h"
# include "cgitems.h"

# define MINIMAPSZ 25

typedef struct t_game
{
	s_cgscreen	*gscreen;
	s_map		*gmap;
	s_player	*gplayer;
	int			resolution;
}	s_game;

s_game	*newgame(int x, int y, int fd, int resolution);
void	endgame(s_game *dat);
int close_game(s_game *cub3d);
void paint_textured_column(s_cgscreen *screen, t_texture *tex, 
                          int screen_x, int wall_height, int tex_x);
#endif