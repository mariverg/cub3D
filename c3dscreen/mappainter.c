#include "cgscreen.h"

void	printmapimg(s_imgdata *data, char **c, int scale)
{
	int i;
	int j;
	int half;

	i = 0;
	half = scale / 2;
	while (c[i])
	{
		j = 0;
		while (c[i][j])
		{
			if (c[i][j] == '1')
			{
				sqaretoimg(data, (j * scale) + half, (i * scale) + half, 0xffffffff, half - 1);
			}
			j++;
		}
		i++;
	}
}