/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raymaker.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariverg <mariverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:38:25 by mariverg          #+#    #+#             */
/*   Updated: 2025/07/31 10:38:25 by mariverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cgitems.h"

float	getver(t_vector *p, float *x, float *y, int cicle)
{
	float	factor;
	float	mi_cos;
	float	defase;
	float	fullnbr;

	mi_cos = cos(p->dir);
	if (mi_cos == 0)
	{
		*x = 100;
		*y = 0;
		return (INFINITY);
	}
	factor = 1 / mi_cos;
	if (mi_cos > 0)
		fullnbr = floorf(p->x) + 1 + cicle;
	else
		fullnbr = floorf(p->x) - cicle;
	defase = fullnbr - p->x;
	factor = fabsf(factor * defase);
	*x = fullnbr;
	*y = p->y + (sin(p->dir) * factor);
	return (factor);
}

float	gethor(t_vector *p, float *x, float *y, int cicle)
{
	float	factor;
	float	misin;
	float	defase;
	float	fullnbr;

	misin = sin(p->dir);
	if (misin == 0)
	{
		*x = 0;
		*y = 100;
		return (INFINITY);
	}
	factor = 1 / misin;
	if (misin > 0)
		fullnbr = floorf(p->y) + 1 + cicle;
	else
		fullnbr = floorf(p->y) - cicle;
	defase = fullnbr - p->y;
	factor = fabsf(factor * defase);
	*x = (cos(p->dir) * factor) + p->x;
	*y = fullnbr;
	return (factor);
}

int	securemap(int x, int y, char **map)
{
	char	*aux;

	if (x < 0 || y < 0)
		return (0);
	while (y > 0)
	{
		map++;
		if (!(*map))
			return (0);
		y--;
	}
	aux = *map;
	while (x > 0)
	{
		aux++;
		if (!(*aux))
			return (0);
		x--;
	}
	if ((*aux) == '1')
		return (1);
	else
		return (0);
}
