#include "cgplayer.h"

s_player	*newplayer(int x, int y, float dir)
{
	s_player	*res;

	res = malloc(sizeof(s_player));
	if (!res)
		return (0);
	res->x = x;
	res->y = y;
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

void	getverpoint(s_player *p, float len, float *x, float *y)
{
	float	factor;
	float	micos;

	micos = cos(p->dir);
	if (micos != 0)
		factor = 1 / micos;
	else 
	{
		*x = 0;
		*y = 0;
		return ;
	}
	if (factor < 0)
		factor = -factor;
	len = len * factor;
	*x = cos(p->dir) * len;
	*y = sin(p->dir) * len;
	*x = p->x + *x;
	*y = p->y + *y;	
}

void	gethorpoint(s_player *p, float len, float *x, float *y)
{
	float	factor;
	float	misin;

	misin = sin(p->dir);
	if (misin != 0)
		factor = 1 / misin;
	else 
	{
		*x = 0;
		*y = 0;
		return ;
	}
	if (factor < 0)
		factor = -factor;
	len = len * factor;
	*x = cos(p->dir) * len;
	*y = sin(p->dir) * len;
	*x = p->x + *x;
	*y = p->y + *y;	
}