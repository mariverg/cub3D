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
	res->strifing = 0;
	res->turning = 0;
	res->resolution = resolution;
	res->renderdata = malloc(sizeof(float) * (resolution * 3));
	if (!res->renderdata)
		return (0);
	if (dir == 'N')
		res->position.dir = 4.7124;
	else if (dir == 'E')
		res->position.dir = 0;
	else if (dir == 'S')
		res->position.dir = 1.5708;
	else if (dir == 'W')
		res->position.dir = 3.1416;
	else
	{
		perror("player load failed\n");
		return (0);
	}
	return (res);
}

void	endplayer(s_player *dat)
{
	free(dat->renderdata);
	free(dat);
}

s_map	*ceromap()
{
	s_map	*res;

	res = malloc(sizeof(s_map));
	if (!res)
		return (0);
	res->px = 0;
	res->py = 0;
	res->pdir = 0;
	res->textures[0] = 0;
	res->textures[1] = 0;
	res->textures[2] = 0;
	res->textures[3] = 0;
	res->fcolor = 0;
	res->ccolor = 0;
	res->raw = 0;
	res->maxy = 0;
	return (res);
}

int validatemaptile(char **map, int x, int y)
{
	if (x == 0 || y == 0)
		return (0);
	if (map[x - 1][y] != '0' && map[x - 1][y] != '1')
		return (0);
	if (map[x][y - 1] != '0' && map[x][y - 1] != '1')
		return (0);
	if (map[x][y + 1] != '0' && map[x][y + 1] != '1')
		return (0);
	if (map[x + 1] == 0)
		return (0);
	if (map[x + 1][y] != '0' && map[x + 1][y] != '1')
		return (0);
	return (1);
}

int validatemapstructure(char **map)
{
	int i;
	int j;
	i = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j])
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

int validatemap(s_map *map)
{
	if (!map->px || !map->py || !map->pdir)
		return (1);
	if (!map->textures[0] || !map->textures[1] || !map->textures[2] || !map->textures[3])
		return (2);
	if (!map->raw)
		return (3);
	if (!validatemapstructure(map->raw))
		return (4);
	return (0);
}

s_map	*initmap(int fd, void *mlx_ptr)
{
	s_map *res;
	t_list	*milines;
	t_list	*aux;

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
	// filltextures2(res, milines, mlx_ptr);
	while (milines)
	{
		aux = milines;
		milines = milines->next;
		if (aux->content)
			free(aux->content);
		free(aux);
	}
	if (!validatemap(res))
	{
		printmapdata(res);
		return (res);
	}
	else
	{
		printf ("required data missing, code = %i\n", validatemap(res));
		exit (0);
	}
}

void	endmap(s_map *dat)
{
	int i;

	i = 0;
	while (i < 4)
	{
		// if (dat->wall_textures[i])
		// 	free(dat->wall_textures[i]);
		free(dat->textures[i]);
		i++;
	}
	emptymap(dat);
	free(dat);
}