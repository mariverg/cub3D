#include "cub3d.h"

s_game	*newgame(int x, int y, int fd, int resolution)
{
	s_game	*res;

	res = malloc(sizeof(s_game));
	if (!res)
		return (0);
	res->resolution = resolution;
	res->gscreen = initcgscreen(x, y);
	res->gmap = initmap(fd);
	res->gplayer = initplayer(res->gmap->px, res->gmap->py, res->gmap->pdir, resolution);
	return (res);
}

void	endgame(s_game *dat)
{
	endcgmlx(dat->gscreen);
	endmap(dat->gmap);
	endplayer(dat->gplayer);
	free(dat);
}