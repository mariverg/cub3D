#include "cub3d.h"
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>

int	dokeydown(int keycode, t_game *param)
{
	if (keycode == 65307)
		close_game(param);
	else if (keycode == 65361)
		param->gplayer->turning = -1;
	else if (keycode == 65363)
		param->gplayer->turning = 1;
	else if (keycode == 'd')
		param->gplayer->strifing = 1;
	else if (keycode == 'a')
		param->gplayer->strifing = -1;
	else if (keycode == 'w')
		param->gplayer->moving = 1;
	else if (keycode == 's')
		param->gplayer->moving = -1;
	return (0);
}

int	dokeyup(int keycode, t_game *param)
{
	if (keycode == 65361)
		param->gplayer->turning = 0;
	else if (keycode == 65363)
		param->gplayer->turning = 0;
	else if (keycode == 'd')
		param->gplayer->strifing = 0;
	else if (keycode == 'a')
		param->gplayer->strifing = 0;
	else if (keycode == 'w')
		param->gplayer->moving = 0;
	else if (keycode == 's')
		param->gplayer->moving = 0;
	return (0);
}

int	update(t_game *cub3d)
{
	updateplayer(cub3d->gplayer, cub3d->gmap->raw);
	fillscreenimg(cub3d->gscreen, cub3d->gmap->ccolor, cub3d->gmap->fcolor);
	paint3d(cub3d->gscreen, cub3d->gplayer->renderdata, cub3d->resolution);
	printmapimg(cub3d->gscreen->imgdata, cub3d->gmap->raw, MINIMAPSZ);
	updatescreen(cub3d->gscreen);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*cub3d;
	int		fd;

	(void) argc;
	(void) argv;
	fd = open("mapaa.cub", O_RDONLY);
	if (fd == -1)
	{
		printf("error loading .cub\n");
		exit (1);
	}
	cub3d = newgame(800, 600, fd, 800);
	mlx_hook(cub3d->gscreen->win, 2, (1L << 0), dokeydown, cub3d);
	mlx_hook(cub3d->gscreen->win, 3, (1L << 1), dokeyup, cub3d);
	mlx_hook(cub3d->gscreen->win, 17, 0, close_game, cub3d);
	mlx_loop_hook(cub3d->gscreen->mlx, update, cub3d);
	mlx_loop(cub3d->gscreen->mlx);
	endgame(cub3d);
	return (0);
}
