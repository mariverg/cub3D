#include "cgscreen.h"

t_imgdata	*initimg(t_cgscreen *dat)
{
	t_imgdata	*res;

	res = malloc(sizeof(t_imgdata));
	if (!res)
		return (0);
	res->img = mlx_new_image(dat->mlx, dat->wide, dat->tall);
	res->addr = mlx_get_data_addr(res->img, &res->bits_per_pixel,
			&res->line_length, &res->endian);
	res->tall = dat->tall;
	res->wide = dat->wide;
	return (res);
}

t_cgscreen	*initcgscreen(int w, int h)
{
	t_cgscreen	*res;
	int			i;

	res = malloc(sizeof(t_cgscreen));
	if (!res)
		return (0);
	res->wide = w;
	res->tall = h;
	i = 0;
	while (i < 4)
	{
		res->wall_textures[i] = 0;
		i++;
	}
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

void	endcgmlx(t_cgscreen *dat)
{
	int	i;

	if (dat)
	{
		i = 0;
		while (i < 4)
		{
			if (dat->wall_textures[i])
			{
				free_texture(dat->mlx, dat->wall_textures[i]);
			}
			i++;
		}
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

void	updatescreen(t_cgscreen *dat)
{
	mlx_put_image_to_window(dat->mlx, dat->win, dat->imgdata->img, 0, 0);
}
