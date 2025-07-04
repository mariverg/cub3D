#include "cub3d.h"

t_game	*newgame(int x, int y, int fd, int resolution)
{
	t_game	*res;

	res = malloc(sizeof(t_game));
	if (!res)
		return (0);
	res->resolution = resolution;
	res->gscreen = initcgscreen(x, y);
	if (!res->gscreen)
		return (0);
	res->gmap = initmap(fd);
	if (!res->gmap)
		return (0);
	loadtextures(res->gscreen, res->gmap->textures);
	res->gplayer = initplayer(res->gmap->px, res->gmap->py,
			res->gmap->pdir, resolution);
	if (!res->gplayer)
		return (0);
	return (res);
}

void	endgame(t_game *dat)
{
	endcgmlx(dat->gscreen);
	endmap(dat->gmap);
	endplayer(dat->gplayer);
	free(dat);
}

int	close_game(t_game *cub3d)
{
	endgame(cub3d);
	exit(0);
	return (0);
}
