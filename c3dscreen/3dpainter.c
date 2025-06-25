#include "cgscreen.h"

void	paintcollumn(t_cgscreen *m, int xd, int wid, float *distance)
{
	t_intgroup	tig;
	float		fy;

	tig.iy = m->tall / distance[0];
	if (tig.iy > (m->tall * 20))
		tig.iy = m->tall * 20;
	tig.ix = m->tall / 2;
	tig.x = 0;
	while (tig.x < wid)
	{
		tig.y = tig.ix - tig.iy;
		while (tig.y < tig.ix + tig.iy)
		{
			fy = (float)(tig.y - (tig.ix - tig.iy)) / (tig.iy * 2);
			if (tig.y >= 0 && tig.y <= m->tall)
				pixeltoimg(m->imgdata, tig.x + xd, tig.y,
					get_pixel_color(m->wall_textures[(int)(distance[1])],
						distance[2], fy));
			tig.y++;
		}
		tig.x++;
	}
}

void	paint3d(t_cgscreen *m, float *renderdata, int resolution)
{
	t_intgroup	tig;
	float		stepsizef;
	float		x;
	int			i;

	stepsizef = (float)m->wide / resolution;
	x = 0.0f;
	i = 0;
	while (i < resolution)
	{
		tig.x = (int)roundf(x);
		tig.ix = (int)roundf(x + stepsizef);
		tig.y = tig.ix - tig.x;
		if (tig.y > 0)
			paintcollumn(m, tig.x, tig.y, &renderdata[i * 3]);
		x += stepsizef;
		i++;
	}
}
