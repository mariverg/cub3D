#include "cgmlx.h"
#include "unistd.h"
#include <stdio.h>

void colpixeltoscreen(s_cgmlx *m, int x, int y, s_cgcolor *col)
{
	int color = colortoint(col);
	if (x < 0 || y < 0 || x > m->wide || y > m->tall)
		return ;
	mlx_pixel_put(m->mlx, m->win, x, y, color);
}

void pixeltoscreen(s_cgmlx *m, int x, int y)
{
	s_cgcolor blanco = colorgreen();
	int color = colortoint(&blanco);
	if (x < 0 || y < 0 || x > m->wide || y > m->tall)
		return ;
	mlx_pixel_put(m->mlx, m->win, x, y, 255);
}

void sqaretosecreen(s_cgmlx *m, int x, int y)
{
	int i = -4;
	int j = -4;

	while (i <= 4)
	{
		j = -4;
		while (j <= 4)
		{
			pixeltoscreen(m, x + i, y + j);
			j++;
		}
		i++;
	}
}

void linetoscreen(s_cgmlx *m, int xa, int ya, int xb, int yb)
{
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
		pixeltoscreen(m, xa, ya);
		if (xa == xb && ya == yb)
			break;
		int e2 = 2 * err;
		if (e2 > -dy) { err -= dy; xa += sx; }
		if (e2 < dx)  { err += dx; ya += sy; }
	}
}

void fillscreen(s_cgmlx *m)
{
	int 		i;
	int 		j;
	s_cgcolor	col;
	int			color;

	i = 0;
	col = colorblack();
	color = colortoint(&col);
	while (i < m->wide)
	{
		j = 0;
		while (j < m->tall){
			mlx_pixel_put(m->mlx, m->win, i, j, color);
			j++;
		}
		i++;
	}
}


void paintmap(s_cgmlx *m, char	**raw, float sz)
{
	int 		i;
	int 		j;
	s_cgcolor	col;
	int			color;

	i = 0;
	col = colorwhite();
	color = colortoint(&col);
	while (raw[i])
	{
		j = 0;
		while (raw[i][j]){
			sqaretosecreen(m, i * sz, j * sz);
			j++;
		}
		i++;
	}
}