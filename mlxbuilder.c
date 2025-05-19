#include "cgmlx.h"

s_imgdata	*initimg(s_cgmlx *cgmlx)
{
	s_imgdata	*res;

	res = malloc(sizeof(s_imgdata));
	res->img = mlx_new_image(cgmlx->mlx, cgmlx->wide, cgmlx->tall);
	res->addr = mlx_get_data_addr(res->img, &res->bits_per_pixel, &res->line_length, &res->endian);
	res->tall = cgmlx->tall;
	res->wide = cgmlx->wide;
	return (res);
}

s_cgmlx *initcgmlx(int w, int h)
{
	s_cgmlx *res;

	res = malloc(sizeof(s_cgmlx));
	if (!res)
		return (0);
	res->wide = w;
	res->tall = h;
	res->mlx = mlx_init();
	res->win = mlx_new_window(res->mlx, res->wide, res->tall, "Hola MiniLibX");
	res->imgdata = initimg(res);
	return (res);
}