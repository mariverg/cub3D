#include "cgscreen.h"

void paintcollumn(s_cgscreen *m, int xd, int wid, float distance, int col)
{
	int x;
	int y;
	int	dy;
	int	centery;
	int color = col;

	if (distance > 2)
		dy = m->tall / distance;
	else
		dy = m->tall / 2;
	// if (distance > 1)
	// {
	// 	color = color - (distance * 20);
	// 	if (color < 0)
	// 	{
	// 		color = 10; 
	// 	}
	// }
	centery = m->tall / 2;

	x = 0;
	while (x < wid)
	{
		y = centery - dy;
		while (y < centery + dy)
		{
			pixeltoimg(m->imgdata, x + xd, y, color);
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
	int col;
	while (i < resolution)
	{
		int xd = (int)roundf(x);
		int next_xd = (int)roundf(x + stepsizef);
		int width = next_xd - xd;
		if (width > 0)
		{
			if (renderdata[(i * 3) + 1] == 0)
				col = 255;
			else if(renderdata[(i * 3) + 1] == 1)
				col = 0x0000ff00;
			else if(renderdata[(i * 3) + 1] == 2)
				col = 0x00ff0000;
			else if(renderdata[(i * 3) + 1] == 3)
				col = 0x00aaaaaa;
			paintcollumn(m, xd, width, renderdata[i * 3], col);
		}
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