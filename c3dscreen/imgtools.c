#include "cgscreen.h"

void	pixeltoimg(t_imgdata *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= data->wide || y >= data->tall)
	{
		return ;
	}
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	sqaretoimg(t_imgdata *data, t_intgroup *tig, int sz)
{
	int	i;
	int	j;

	i = -sz;
	while (i <= sz)
	{
		j = -sz;
		while (j <= sz)
		{
			pixeltoimg(data, tig->x + i, tig->y + j, tig->color);
			j++;
		}
		i++;
	}
}

void	fillscreenimg(t_cgscreen *m, int colorc, int colorf)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	color = colorc;
	while (i < m->tall)
	{
		if (i == m->tall / 2)
			color = colorf;
		j = 0;
		while (j < m->wide)
		{
			pixeltoimg(m->imgdata, j, i, color);
			j++;
		}
		i++;
	}
}
