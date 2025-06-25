#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h" 
# include "cgscreen.h"
# include "cgitems.h"

# define MINIMAPSZ 25

typedef struct s_game
{
	t_cgscreen	*gscreen;
	t_map		*gmap;
	t_player	*gplayer;
	int			resolution;
}	t_game;

t_game	*newgame(int x, int y, int fd, int resolution);
void	endgame(t_game *dat);
int		close_game(t_game *cub3d);
#endif