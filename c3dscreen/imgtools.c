#include "cgscreen.h"

void	pixeltoimg(s_imgdata *data, int x, int y, int color)
{
	char	*dst;

	// printf("px %i to img, tam %i bpp %i endian %i\n", x, data->line_length, data->bits_per_pixel, data->endian);
	if(x < 0 || y < 0 || x >= data->wide || y >= data->tall)
	{
		return ;
	}
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	sqaretoimg(s_imgdata *data, int x, int y, int color, int sz)
{
	int i;
	int j;

	i = -sz;
	while (i <= sz)
	{
		j = -sz;
		while (j <= sz)
		{
			pixeltoimg(data, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	paraleltoimg(s_imgdata *data, int xa, int ya, int color, int xb, int yb)
{
	int i;
	int j;

	i = xa;
	while (i <= xb)
	{
		j = ya;
		while (j <= yb)
		{
			pixeltoimg(data, i, j, color);
			j++;
		}
		i++;
	}
}

void fillscreenimg(s_cgscreen *m, int colorc, int colorf)
{
	int 		i;
	int 		j;
	int			color;

	i = 0;
	color = colorc;
	while (i < m->tall)
	{
		if (i == m->tall / 2)
			color = colorf;
		j = 0;
		while (j < m->wide){
			pixeltoimg(m->imgdata, j, i, color);
			j++;
		}
		i++;
	}
}

void fillscreenimggrid(s_cgscreen *m, int line)
{
	int 		i;
	int 		j;
	s_cgcolor	col;
	int			color;
	line = line * 2;

	i = 0;
	col = colorwhite();
	color = colortoint(&col);
	while (i < m->wide)
	{
		j = 0;
		while (j < m->tall){
			if (i % line == 0 || j % line == 0)
				pixeltoimg(m->imgdata, i, j, 0xffffffff);
			else
				pixeltoimg(m->imgdata, i, j, 0);
			j++;
		}
		i++;
	}
}

void linetoimg(s_cgscreen *m, int xa, int ya, int xb, int yb)
{
	if (xb < 0 || xb > 800)
		return;
	int dx = xb - xa;
	if (dx < 0)
		dx = -dx;
	int dy = yb - ya;
	if (dy < 0)
		dy = -dy;
	int sx = (xa < xb) ? 1 : -1;
	int sy = (ya < yb) ? 1 : -1;
	int err = dx - dy;

	while (1)
	{
		pixeltoimg(m->imgdata, xa, ya, 0xffff0000);
		if (xa == xb && ya == yb)
			break;
		int e2 = 2 * err;
		if (e2 > -dy) { err -= dy; xa += sx; }
		if (e2 < dx)  { err += dx; ya += sy; }
	}
}

void paintmapimg(s_cgscreen *m, char **raw, float sz)
{
	int 		i;
	int 		j;
	s_cgcolor	col;
	int			color;
	int			half;

	half = sz / 2;
	i = 0;
	col = colorwhite();
	color = colortoint(&col);
	while (raw[i])
	{
		j = 0;
		while (raw[i][j]){
			if (raw[i][j] == '1')
			{
				sqaretoimg(m->imgdata, i * sz + half, j * sz + half, color, half);
			}
			j++;
		}
		i++;
	}
}