#include "cgitems.h"

s_player	*initplayer(float x, float y, char dir, int resolution)
{
	s_player	*res;

	res = malloc(sizeof(s_player));
	if (!res)
		return (0);
	res->position.x = x + 0.5;
	res->position.y = y + 0.5;
	res->moving = 0;
	res->turning = 0;
	res->resolution = resolution;
	res->renderdata = malloc(sizeof(float) * (resolution * 2));
	if (!res->renderdata)
		return (0);
	if (dir == 'N')
		res->position.dir = 1.6;
	else if (dir == 'E')
		res->position.dir = 0;
	else if (dir == 'S')
		res->position.dir = 3.14;
	else if (dir == 'O')
		res->position.dir = 4.8;
	return (res);
}

void	endplayer(s_player *dat)
{
	free(dat->renderdata);
	free(dat);
}

s_map	*initmap(int fd)
{
	s_map *res;
	t_list	*milines;
	t_list	*aux;

	res= malloc(sizeof(s_map));
	if (!res)
		return (0);
	milines = extractlines(fd);
	if (!milines)
		return (0);
	fillmap(res, milines);
	fillplayer(res);
	fillcolors(res, milines);
	filltextures(res, milines);
	while (milines)
	{
		aux = milines;
		milines = milines->next;
		if (aux->content)
			free(aux->content);
		free(aux);
	}
	printmapdata(res);
	return (res);
}

void	endmap(s_map *dat)
{
	int i;

	i = 0;
	while (i < 4)
	{
		free(dat->textures[i]);
		i++;
	}
	emptymap(dat);
	free(dat);
}