#include "cgmap.h"

s_map	*demomap()
{
	int i;
	int j;
	int sz = 20;
	s_map	*res;

	res = malloc(sizeof(s_map));
	i = 0;
	res->raw = malloc(sizeof(char *) * sz);
	if (!res->raw)
		return (0);
	while (i < sz - 1)
	{
		j = 0;
		res->raw[i] = malloc(sizeof(char) * sz);
		if (!res->raw[i])
			return(0);
		while(j < sz - 1)
		{
			if (j == 0 || j == (sz - 2) || i == 0 || i == (sz - 2))
				res->raw[i][j] = '1';
			else
				res->raw[i][j] = '0';
			j++;
		}
		res->raw[i][j] = 0;
		i++;
	}
	res->raw[4][1] = '1';
	res->raw[4][2] = '1';
	res->raw[i] = 0;
	res->lsize = 100;
	return (res);
}