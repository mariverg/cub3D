/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariverg <mariverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:41:16 by mariverg          #+#    #+#             */
/*   Updated: 2025/07/31 10:41:17 by mariverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cgscreen.h"

int	get_pixel_color2(t_texture *tex, int x, int y)
{
	int	offset;

	if (x < 0 || x >= tex->width || y < 0 || y >= tex->height)
		return (0x00000000);
	offset = y * tex->line_len + x * (tex->bpp / 8);
	return (*(int *)(tex->addr + offset));
}

int	get_pixel_color(t_texture *tex, float x, float y)
{
	int	xscaled;
	int	yscaled;
	int	offset;

	if (x < 0 || x > 1 || y < 0 || y > 1)
		return (0x00000000);
	xscaled = x * tex->width;
	yscaled = y * tex->height;
	offset = yscaled * tex->line_len + xscaled * (tex->bpp / 8);
	return (*(int *)(tex->addr + offset));
}
