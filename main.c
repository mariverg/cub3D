#include "cub3d.h"
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>

int dokeydown(int keycode, s_game *param)
{
	if (keycode == 65307)
    close_game(param);
	if (keycode == 'd')
		param->gplayer->turning = 1;
	else if (keycode == 'a')
		param->gplayer->turning = -1;
	else if (keycode == 'w')
		param->gplayer->moving = 1;
	else if (keycode == 's')
		param->gplayer->moving = -1;
	return (0);
}
int dokeyup(int keycode, s_game *param)
{

	if (keycode == 'd')
		param->gplayer->turning = 0;
	else if (keycode == 'a')
		param->gplayer->turning = 0;
	else if (keycode == 'w')
		param->gplayer->moving = 0;
	else if (keycode == 's')
		param->gplayer->moving = 0;
	return (0);
}

int domouse(int button, int x, int y, s_game *param)
{
	write(1, "hola", 4);
	return (0);
}
int domousemove(int x, int y, s_game *param)
{
	write(1, "hola", 4);
	return (0);
}

int update(s_game *cub3d)
{

	float x = 1;
	float y = 1;
	updateplayer(cub3d->gplayer, cub3d->gmap->raw);
	fillscreenimg(cub3d->gscreen, cub3d->gmap->ccolor, cub3d->gmap->fcolor);
	paint3d(cub3d->gscreen, cub3d->gplayer->renderdata, cub3d->resolution);
	printmapimg(cub3d->gscreen->imgdata, cub3d->gmap->raw, MINIMAPSZ);
	castray(&(cub3d->gplayer->position), &x, &y, cub3d->gmap->raw);
	// printf("la pos es x=%f y=%f\n", cub3d->gplayer->position.x, cub3d->gplayer->position.y);
	linetoimg(cub3d->gscreen, cub3d->gplayer->position.x * MINIMAPSZ, cub3d->gplayer->position.y * MINIMAPSZ, x * MINIMAPSZ, y * MINIMAPSZ);
	
	updatescreen(cub3d->gscreen);
	return (0);
}

/* int main(int argc, char **argv)
{
	s_game	*cub3d;
	int fd;

	fd = open("mapaa.cub", O_RDONLY);
	cub3d = newgame(800, 600, fd, 400);
	if (!cub3d)
		return (0);

	
	mlx_hook(cub3d->gscreen->win, 2, (1L<<0), dokeydown, cub3d);     // KeyPress
	mlx_hook(cub3d->gscreen->win, 3, (1L<<1), dokeyup, cub3d);       // KeyRelease
	// mlx_hook(cub3d->gscreen->win, 4, (1L<<2), domouse, cub3d);       // ButtonPress
	// mlx_hook(cub3d->gscreen->win, 5, (1L<<3), domouse, cub3d);       // ButtonRelease
	// mlx_hook(cub3d->gscreen->win, 6, (1L<<6), domousemove, cub3d);   // MotionNotify
	// update(cub3d);
	
	mlx_loop_hook(cub3d->gscreen->mlx, &update, cub3d);
	mlx_loop(cub3d->gscreen->mlx);
	
	endgame(cub3d);
	return (0);
} */


int main(int argc, char **argv) {
    s_game *cub3d;
    int fd;

	fd = open("mapaa.cub", O_RDONLY);
    cub3d = newgame(800, 600, fd, 150);

    mlx_hook(cub3d->gscreen->win, 2, (1L << 0), dokeydown, cub3d);
    mlx_hook(cub3d->gscreen->win, 3, (1L << 1), dokeyup, cub3d);
    mlx_hook(cub3d->gscreen->win, 17, 0, close_game, cub3d);
    mlx_loop_hook(cub3d->gscreen->mlx, update, cub3d);

    mlx_loop(cub3d->gscreen->mlx);
	endgame(cub3d);
    return (0);
}