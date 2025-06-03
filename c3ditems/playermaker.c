#include "cgitems.h"

void	calculaterender(s_player *dat, char **map)
{
	int i;
	float x;
	float y;
	s_vector v;
	v.x = dat->position.x;
	v.y = dat->position.y;
	v.dir = dat->position.dir;

	i = 0;
	float displacedir = (dat->resolution / 2) * (-0.01) ;
	v.dir += displacedir;
	while (i < dat->resolution)
	{
		v.dir += 0.01;
		dat->renderdata[i * 2] = castray(&v, &x, &y, map);
		i++;
	}
}

void	moveplayer(s_player *dat, float vel)
{
	float	x;
	float	y;

	x = vel * (cos(dat->position.dir));
	y = vel * (sin(dat->position.dir));
	dat->position.x = dat->position.x + x;
	dat->position.y = dat->position.y + y;
}

void	updateplayer(s_player *dat, char **map)
{
	if (dat->moving == 1)
	{
		moveplayer(dat, 0.005);
	}
	else if (dat->moving == -1)
	{
		moveplayer(dat, -0.005);
	}

	if (dat->turning == 1)
	{
		dat->position.dir = dat->position.dir + 0.005;
	}
	else if (dat->turning == -1)
	{
		dat->position.dir = dat->position.dir - 0.005;
	}
	calculaterender(dat, map);
}