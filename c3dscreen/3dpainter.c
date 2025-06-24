#include "cgscreen.h"

void paintcollumn(s_cgscreen *m, int xd, int wid, float *distance)
{
	int x;
	int y;
	int	dy;
	int	centery;
	float fx;
	float fy;

	dy = m->tall / distance[0];
	if (dy > (m->tall * 20))
		dy = m->tall * 20;
	centery = m->tall / 2;
	int	indtextura = (int) distance[1] ;
	x = 0;
	while (x < wid)
	{
		y = centery - dy;
		while (y < centery + dy)
		{
			fx = distance[2];
			fy = (float)((float)(y - (centery - dy)) / (float)(dy * 2));
			if (y >= 0 && y <= m->tall)
				pixeltoimg(m->imgdata, x + xd, y, get_pixel_color(m->wall_textures[indtextura], fx, fy));
			y++;
		}
		x++;
	}

}

void	paint3d(s_cgscreen *m, float *renderdata, int resolution)
{
	float stepsizef = (float)m->wide / resolution;
	float x = 0.0f;
	int i = 0;

	while (i < resolution)
	{
		int xd = (int)roundf(x);
		int next_xd = (int)roundf(x + stepsizef);
		int width = next_xd - xd;
		if (width > 0)
			paintcollumn(m, xd, width, &renderdata[i * 3]);
		x += stepsizef;
		i++;
	}
}

/*void	paint3d(s_cgscreen *m, float *renderdata, int resolution)
{
	int i;
	char c;
	int stepsize;
	
	stepsize = m->wide / resolution;
	i = 0;
	while (i < resolution)
	{
		paintcollumn(m, i * stepsize, stepsize, renderdata[i * 2]);
		i++;
	}
}*/