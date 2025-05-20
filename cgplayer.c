#include "cgplayer.h"

s_player	*newplayer(float x, float y, float dir)
{
	s_player	*res;

	res = malloc(sizeof(s_player));
	if (!res)
		return (0);
	res->x = x + 0.5;
	res->y = y + 0.5;
	res->dir = dir;
	res->speed = 0;
	return (res);
}

void	moveplayer(s_player *p, float x, float y)
{
	p->x = p->x + x;
	p->y = p->y + y;
}

void	displaceplayer(s_player *p)
{
	float dx;
	float dy;

	if (!p->speed)
	{
		return ;
	}
	dx = cos(p->dir) * p->speed;
	dy = sin(p->dir) * p->speed;
	p->x = p->x + dx;
	p->y = p->y + dy;	
}

void	getpathpoint(s_player *p, float len, float *x, float *y)
{
	*x = cos(p->dir) * len;
	*y = sin(p->dir) * len;
	*x = p->x + *x;
	*y = p->y + *y;	
}

float	getnextcross(float *x, float *y, float sinfac, float cosfac, char **map)
{
	
}

float	getverpoint(s_player *p, float *x, float *y)
{
	float	factor;
	float	micos;
	float	defase;
	int		fullnbr;

	micos = cos(p->dir);
	if (micos != 0)
		factor = 1 / micos;
	else 
	{
		*x = 0;
		*y = 0;
		return (100);
	}
	if (micos > 0)
	{
		fullnbr = (int)p->x + 1;
		defase = fullnbr - p->x;
	}
	else
	{
		fullnbr = (int)p->x;
		defase = p->x - fullnbr;
	}
	factor = factor * defase;
	if (factor < 0)
		factor = -factor;
	*x = cos(p->dir) * factor;
	*y = sin(p->dir) * factor;
	*x = p->x + *x;
	*y = p->y + *y;
	return (factor);
}

float	gethorpoint(s_player *p, float *x, float *y)
{
	float	factor;
	float	misin;
	float	defase;
	int		fullnbr;

	misin = sin(p->dir);
	if (misin != 0)
		factor = 1 / misin;
	else 
	{
		*x = 0;
		*y = 0;
		return (100);
	}
	if (misin > 0)
	{
		fullnbr = (int)p->y + 1;
		defase = fullnbr - p->y;
	}
	else
	{
		fullnbr = (int)p->y;
		defase = p->y - fullnbr;
	}
	factor = factor * defase;
	if (factor < 0)
		factor = -factor;
	*x = cos(p->dir) * factor;
	*y = sin(p->dir) * factor;
	*x = p->x + *x;
	*y = p->y + *y;
	return (factor);
}