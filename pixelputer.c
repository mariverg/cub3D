#include "mlxcontrols.h"

void pixeltoscreen(s_cgmlx *m, int x, int y)
{
	s_cgcolor blanco = colorgreen();
	int color = colortoint(&blanco);
	if (x < 0 || y < 0 || x > m->wide || y > m->heigth)
		return ;
	mlx_pixel_put(m->mlx, m->win, x, y, color);
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