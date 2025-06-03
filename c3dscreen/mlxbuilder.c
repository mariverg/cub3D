#include "cgscreen.h"

s_imgdata	*initimg(s_cgscreen *dat)
{
	s_imgdata	*res;

	res = malloc(sizeof(s_imgdata));
	if (!res)
		return (0);
	res->img = mlx_new_image(dat->mlx, dat->wide, dat->tall);
	res->addr = mlx_get_data_addr(res->img, &res->bits_per_pixel, &res->line_length, &res->endian);
	res->tall = dat->tall;
	res->wide = dat->wide;
	return (res);
}

s_cgscreen *initcgscreen(int w, int h)
{
	s_cgscreen *res;

	res = malloc(sizeof(s_cgscreen));
	if (!res)
		return (0);
	res->wide = w;
	res->tall = h;
	res->mlx = mlx_init();
	if (!res->mlx)
		return (0);
	res->win = mlx_new_window(res->mlx, res->wide, res->tall, "Hola MiniLibX");
	if (!res->win)
		return (0);
	res->imgdata = initimg(res);
	if (!res->imgdata)
		return (0);
	return (res);
}

// mlx_destroy_display solo es necesario en Linux
// En Linux, mlx_init hace un malloc
void endcgmlx(s_cgscreen *dat)
{
	if (dat)
	{
		if (dat->mlx && dat->imgdata && dat->imgdata->img)
			mlx_destroy_image(dat->mlx, dat->imgdata->img);
		if (dat->mlx && dat->win)
			mlx_destroy_window(dat->mlx, dat->win);
		if (dat->imgdata)
			free(dat->imgdata);
		if (dat->mlx)
			mlx_destroy_display(dat->mlx);
		free(dat->mlx);
		free(dat);
	}
}

void updatescreen(s_cgscreen *dat)
{
	mlx_put_image_to_window(dat->mlx, dat->win, dat->imgdata->img, 0, 0);
}