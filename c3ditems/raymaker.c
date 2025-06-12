#include "cgitems.h"

float getverpoint(s_vector *p, float *x, float *y, int cicle)
{
	float factor;
	float mi_cos;
	float defase;
	float fullnbr;

	mi_cos = cos(p->dir);
	if (mi_cos != 0)
		factor = 1 / mi_cos;
	else 
	{
		*x = 100;
		*y = 0;
		return (INFINITY);
	}

	if (mi_cos > 0)
		fullnbr = floorf(p->x) + 1 + cicle;
	else
		fullnbr = floorf(p->x) - cicle;
	defase = fullnbr - p->x;
	factor = fabsf(factor * defase);
	*x = fullnbr;
	*y = p->y + (sin(p->dir) * factor);
	return (factor);
}


float	gethorpoint(s_vector *p, float *x, float *y, int cicle)
{
	float	factor;
	float	misin;
	float	defase;
	float	fullnbr;

	misin = sin(p->dir);
	if (misin != 0)
		factor = 1 / misin;
	else 
	{
		*x = 0;
		*y = 100;
		return (INFINITY);
	}
	if (misin > 0)
		fullnbr = floorf(p->y) + 1 + cicle;
	else
		fullnbr = floorf(p->y) - cicle;
	defase = fullnbr - p->y;
	factor = fabsf(factor * defase);
	*x = (cos(p->dir) * factor) + p->x;
	*y = fullnbr;
	return (factor);
}

int securemap(int x, int y, char **map)
{
	char	*aux;

	if (x < 0 || y < 0)
		return (0);
	while (y > 0)
	{
		map++;
		if (!(*map))
			return (0);
		y--;
	}
	aux = *map;
	while (x > 0)
	{
		aux++;
		if (!(*aux))
			return (0);
		x--;
	}
	if ((*aux) == '1')
		return (1);
	else
		return (0);
}

int inmap(float x, float y, int cuad, float angle, char **map)
{
	int ix = (int)x;
	int iy = (int)y;

	if (cuad == 0) // Horizontal
	{
		// Si el rayo va hacia arriba, revisamos la celda de arriba
		if (sin(angle) > 0)
			return securemap(ix, iy, map);
		else
			return securemap(ix, iy - 1, map);
	}
	else // Vertical
	{
		// Si el rayo va hacia la derecha, revisamos la celda de la derecha (en la que estamos)
		if (cos(angle) > 0)
			return securemap(ix, iy, map);
		else
			return securemap(ix - 1, iy, map);
	}
}

// int inmap(float x, float y, int cuad, char **map)
// {
// 	int ix = (int)x;
// 	int iy = (int)y;

// 	if (cuad == 0) // Horizontal
// 	{
// 		if (securemap(ix, iy, map) || securemap(ix, iy - 1, map))
// 			return (1);
// 	}
// 	else // Vertical
// 	{
// 		if (securemap(ix, iy, map) || securemap(ix - 1, iy - 1, map))
// 			return (1);
// 	}
// 	return (0);
// }

float	castray(s_vector *p, float *x, float *y, char **map)
{
	int MAXCICLES = 40;
	s_ray	miray;
	float	disthor;
	float	distver;
	float	res;
	int		cichor = 0;
	int		cicver = 0;

	disthor = gethorpoint(p, &(miray.hx), &(miray.hy), cichor);
	distver = getverpoint(p, &(miray.vx), &(miray.vy), cicver);
	while (1)
	{
		if (disthor <= distver && cichor < MAXCICLES)
		{
			if (inmap(miray.hx, miray.hy, 0, p->dir, map))
			{
				*x = miray.hx;
				*y = miray.hy;
				res = hypot(*x - p->x, *y - p->y);
				// printf("Horizontal en x=%f   y=%f.\n", *x, *y);
				return (res);
			}
			else
			{
				cichor++;
				disthor = gethorpoint(p, &(miray.hx), &(miray.hy), cichor);
			}
		}
		else if (cicver < MAXCICLES)
		{
			if (inmap(miray.vx, miray.vy, 1, p->dir, map))
			{
				*x = miray.vx;
				*y = miray.vy;
				res = hypot(*x - p->x, *y - p->y);
				// printf("Vertical en x=%f   y=%f.\n", *x, *y);
				return (res);
			}
			else
			{
				cicver++;
				distver = getverpoint(p, &(miray.vx), &(miray.vy), cicver);
			}
		}
		else
		    break;
	}
	return (INFINITY);
}

float	castrenderray(s_vector *p, float *cuad, float *dist, char **map)
{
	int MAXCICLES = 40;
	s_ray	miray;
	float	disthor;
	float	distver;
	float	res;
	float	x;
	float	y;
	int		cichor = 0;
	int		cicver = 0;

	disthor = gethorpoint(p, &(miray.hx), &(miray.hy), cichor);
	distver = getverpoint(p, &(miray.vx), &(miray.vy), cicver);
	while (1)
	{
		if (disthor <= distver && cichor < MAXCICLES)
		{
			if (inmap(miray.hx, miray.hy, 0, p->dir, map))
			{
				x = miray.hx;
				y = miray.hy;
				res = hypot(x - p->x, y - p->y);
				if (y - p->y > 0)
					*cuad = 0;
				else
					*cuad = 2;
				*dist = x;
				// printf("Horizontal en x=%f   y=%f.\n", *x, *y);
				return (res);
			}
			else
			{
				cichor++;
				disthor = gethorpoint(p, &(miray.hx), &(miray.hy), cichor);
			}
		}
		else if (cicver < MAXCICLES)
		{
			if (inmap(miray.vx, miray.vy, 1, p->dir, map))
			{
				x = miray.vx;
				y = miray.vy;
				res = hypot(x - p->x, y - p->y);
				if (x - p->x > 0)
					*cuad = 1;
				else
					*cuad = 3;
				*dist = y;
				// printf("Vertical en x=%f   y=%f.\n", *x, *y);
				return (res);
			}
			else
			{
				cicver++;
				distver = getverpoint(p, &(miray.vx), &(miray.vy), cicver);
			}
		}
		else
		    break;
	}
	return (INFINITY);
}