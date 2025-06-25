#include "cgscreen.h"

t_cgcolor	colorwhite(void)
{
	t_cgcolor	res;

	res.a = 0;
	res.r = 255;
	res.g = 255;
	res.b = 255;
	return (res);
}

t_cgcolor	colorblack(void)
{
	t_cgcolor	res;

	res.a = 0;
	res.r = 0;
	res.g = 0;
	res.b = 0;
	return (res);
}

t_cgcolor	colorred(void)
{
	t_cgcolor	res;

	res.a = 0;
	res.r = 255;
	res.g = 0;
	res.b = 0;
	return (res);
}

t_cgcolor	colorgreen(void)
{
	t_cgcolor	res;

	res.a = 0;
	res.r = 0;
	res.g = 255;
	res.b = 0;
	return (res);
}

t_cgcolor	colorblue(void)
{
	t_cgcolor	res;

	res.a = 0;
	res.r = 0;
	res.g = 0;
	res.b = 255;
	return (res);
}
