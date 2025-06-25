#include "cgitems.h"

int	validatemapstructure(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
			{
				if (!validatemaptile(map, i, j))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	validatemap(t_map *map)
{
	if (!map->px || !map->py || !map->pdir)
		return (1);
	if (!map->textures[0] || !map->textures[1]
		|| !map->textures[2] || !map->textures[3])
		return (2);
	if (!map->raw)
		return (3);
	if (!validatemapstructure(map->raw))
		return (4);
	return (0);
}

void	cleanlist(t_list *milines)
{
	t_list	*aux;

	while (milines)
	{
		aux = milines;
		milines = milines->next;
		if (aux->content)
			free(aux->content);
		free(aux);
	}
}

t_map	*initmap(int fd)
{
	t_map	*res;
	t_list	*milines;

	res = ceromap();
	if (!res)
		return (0);
	milines = extractlines(fd);
	if (!milines)
		return (0);
	fillmap(res, milines);
	fillplayer(res);
	fillcolors(res, milines);
	filltextures(res, milines);
	cleanlist(milines);
	if (!validatemap(res))
		return (res);
	else
	{
		printf ("required data missing, code = %i\n", validatemap(res));
		exit (0);
	}
}

void	endmap(t_map *dat)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(dat->textures[i]);
		i++;
	}
	emptymap(dat);
	free(dat);
}
