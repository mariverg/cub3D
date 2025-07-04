#include "cgscreen.h"

void	printmapimg(t_imgdata *data, char **c, int scale)
{
	t_intgroup	tig;
	int			i;
	int			j;
	int			half;

	i = 0;
	half = scale / 2;
	while (c[i])
	{
		j = 0;
		while (c[i][j])
		{
			if (c[i][j] == '1')
			{
				tig.x = (j * scale) + half;
				tig.y = (i * scale) + half;
				tig.color = 0xffffffff;
				sqaretoimg(data, &tig, half - 1);
			}
			j++;
		}
		i++;
	}
}
