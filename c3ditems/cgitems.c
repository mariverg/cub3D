/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cgitems.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariverg <mariverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:36:39 by mariverg          #+#    #+#             */
/*   Updated: 2025/07/31 10:36:41 by mariverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cgitems.h"

void	cleanplayer(t_player *param, float x, float y)
{
	param->position.x = x + 0.5;
	param->position.y = y + 0.5;
	param->moving = 0;
	param->strifing = 0;
	param->turning = 0;
}

t_player	*initplayer(float x, float y, char dir, int resolution)
{
	t_player	*res;

	res = malloc(sizeof(t_player));
	if (!res)
		return (0);
	cleanplayer(res, x, y);
	res->resolution = resolution;
	res->renderdata = malloc(sizeof(float) * (resolution * 3));
	if (!res->renderdata)
		return (0);
	if (dir == 'N')
		res->position.dir = 4.7124;
	else if (dir == 'E')
		res->position.dir = 0.01;
	else if (dir == 'S')
		res->position.dir = 1.5708;
	else if (dir == 'W')
		res->position.dir = 3.1416;
	else
	{
		printf("player load failed\n");
		exit (0);
	}
	return (res);
}

void	endplayer(t_player *dat)
{
	free(dat->renderdata);
	free(dat);
}

t_map	*ceromap(void)
{
	t_map	*res;

	res = malloc(sizeof(t_map));
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

int	validatemaptile(char **map, int x, int y)
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
