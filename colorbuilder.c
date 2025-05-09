#include "mlxcontrols.h"

s_cgcolor colorwhite()
{
	s_cgcolor res;

	res.a = 0;
	res.r = 255;
	res.g = 255;
	res.b = 255;
	return (res);
}
s_cgcolor colorblack()
{
	s_cgcolor res;

	res.a = 0;
	res.r = 0;
	res.g = 0;
	res.b = 0;
	return (res);
}
s_cgcolor colorred()
{
	s_cgcolor res;

	res.a = 0;
	res.r = 255;
	res.g = 0;
	res.b = 0;
	return (res);
}
s_cgcolor colorgreen()
{
	s_cgcolor res;

	res.a = 0;
	res.r = 0;
	res.g = 255;
	res.b = 0;
	return (res);
}
s_cgcolor colorblue()
{
	s_cgcolor res;

	res.a = 0;
	res.r = 0;
	res.g = 0;
	res.b = 255;
	return (res);
}

int colortoint(s_cgcolor *color)
{
	int res = 0;
	int i;

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
