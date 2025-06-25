#include "cgscreen.h"

t_cgcolor	colorrgb(int r, int g, int b)
{
	t_cgcolor	res;

	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		res.a = 0;
		res.r = 0;
		res.g = 0;
		res.b = 0;
		return (res);
	}
	res.a = 0;
	res.r = r;
	res.g = g;
	res.b = b;
	return (res);
}

int	colortoint(t_cgcolor *color)
{
	int	res;
	int	i;

	res = 0;
	i = color->b;
	res += i;
	i = color->g;
	i = i << 8;
	res += i;
	i = color->r;
	i = i << 16;
	res += i;
	i = color->a;
	i = i << 24;
	res += i;
	return (res);
}
