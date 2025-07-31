/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendermaker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariverg <mariverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:38:39 by mariverg          #+#    #+#             */
/*   Updated: 2025/07/31 10:38:40 by mariverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cgitems.h"

int	inmp(float x, float y, int cuad, char **map)
{
	int	ix;
	int	iy;

	ix = (int)x;
	iy = (int)y;
	if (cuad == 0)
	{
		if (securemap(ix, iy, map) || securemap(ix, iy - 1, map))
			return (1);
	}
	else
	{
		if (securemap(ix, iy, map) || securemap(ix - 1, iy, map))
			return (1);
	}
	return (0);
}

float	horrenderray(t_vector *p, float *cuad, float *dist, char **map)
{
	const int	maxcicles = 20;
	t_ray		ray;
	t_vector	dists;
	int			cichor;

	cichor = 0;
	dists.x = gethor(p, &ray.hx, &ray.hy, cichor);
	while (cichor < maxcicles)
	{
		if (inmp(ray.hx, ray.hy, 0, map))
		{
			dists.dir = hypot(ray.hx - p->x, ray.hy - p->y);
			if (ray.hy - p->y > 0)
				*cuad = 0;
			else
				*cuad = 2;
			*dist = ray.hx - (int)ray.hx;
			return (dists.dir);
		}
		cichor++;
		dists.x = gethor(p, &ray.hx, &ray.hy, cichor);
	}
	return (INFINITY);
}

float	verrenderray(t_vector *p, float *cuad, float *dist, char **map)
{
	const int	maxcicles = 20;
	t_ray		ray;
	t_vector	dists;
	int			cicver;

	cicver = 0;
	dists.y = getver(p, &ray.vx, &ray.vy, cicver);
	while (cicver < maxcicles)
	{
		if (inmp(ray.vx, ray.vy, 1, map))
		{
			dists.dir = hypot(ray.vx - p->x, ray.vy - p->y);
			if (ray.vx - p->x > 0)
				*cuad = 3;
			else
				*cuad = 1;
			*dist = ray.vy - (int)ray.vy;
			return (dists.dir);
		}
		cicver++;
		dists.y = getver(p, &ray.vx, &ray.vy, cicver);
	}
	return (INFINITY);
}

float	castrenderray(t_vector *p, float *cuad, float *dist, char **map)
{
	float	verdist;
	float	hordist;
	t_ray	coords;

	verdist = verrenderray(p, &(coords.vx), &(coords.vy), map);
	hordist = horrenderray(p, &(coords.hx), &(coords.hy), map);
	if (verdist <= hordist)
	{
		*cuad = coords.vx;
		*dist = coords.vy;
		return (verdist);
	}
	else
	{
		*cuad = coords.hx;
		*dist = coords.hy;
		return (hordist);
	}
}
