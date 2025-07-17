#include "cgitems.h"

void	calculaterender(t_player *dat, char **map)
{
	int			i;
	t_vector	v;
	float		displacedir;
	float		frontdir;

	v.x = dat->position.x;
	v.y = dat->position.y;
	frontdir = dat->position.dir;
	i = 0;
	displacedir = (dat->resolution / 2) * (-0.001);
	while (i < dat->resolution)
	{
		displacedir = displacedir + 0.001;
		v.dir = frontdir + displacedir;
		dat->renderdata[i * 3] = castrenderray(&v,
				&(dat->renderdata[(i * 3) + 1]),
				&(dat->renderdata[(i * 3) + 2]), map);
		dat->renderdata[i * 3] = dat->renderdata[i * 3] * cos(displacedir);
		i++;
	}
}

void	moveplayer(t_player *dat, float vel, char **map)
{
	float	x;
	float	y;

	(void) map;
	x = vel * 5 * (cos(dat->position.dir));
	y = vel * 5 * (sin(dat->position.dir));
	dat->position.x = dat->position.x + x;
	dat->position.y = dat->position.y + y;
}

void	strifeplayer(t_player *dat, float vel, char **map)
{
	float	x;
	float	y;

	(void) map;
	x = vel * 5 * (cos((dat->position.dir + 1.5707963f)));
	y = vel * 5 * (sin((dat->position.dir + 1.5707963f)));
	dat->position.x = dat->position.x + x;
	dat->position.y = dat->position.y + y;
}

void	updateplayer(t_player *dat, char **map)
{
	if (dat->moving == 1)
	{
		moveplayer(dat, 0.005, map);
	}
	else if (dat->moving == -1)
	{
		moveplayer(dat, -0.005, map);
	}
	if (dat->strifing == 1)
	{
		strifeplayer(dat, 0.005, map);
	}
	else if (dat->strifing == -1)
	{
		strifeplayer(dat, -0.005, map);
	}
	if (dat->turning == 1)
	{
		dat->position.dir = dat->position.dir + 0.02;
	}
	else if (dat->turning == -1)
	{
		dat->position.dir = dat->position.dir - 0.02;
	}
	calculaterender(dat, map);
}

/*void	moveplayer(t_player *dat, float vel, char **map)
{
	float	x;
	float	y;
	int		xi;
	int		yi;

	x = vel * 5 * (cos(dat->position.dir));
	y = vel * 5 * (sin(dat->position.dir));
	xi = dat->position.x + x;
	yi = dat->position.y + y;
	if (map[yi][xi] == '0')
	{
		dat->position.x = dat->position.x + x;
		dat->position.y = dat->position.y + y;
	}
}
void	strifeplayer(t_player *dat, float vel, char **map)
{
	float	x;
	float	y;
	int		xi;
	int		yi;

	x = vel * 5 * (cos((dat->position.dir + 1.5707963f)));
	y = vel * 5 * (sin((dat->position.dir + 1.5707963f)));
	xi = dat->position.x + x;
	yi = dat->position.y + y;
	if (map[yi][xi] == '0')
	{
		dat->position.x = dat->position.x + x;
		dat->position.y = dat->position.y + y;
	}
}*/