/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapmakerbis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariverg <mariverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:37:27 by mariverg          #+#    #+#             */
/*   Updated: 2025/07/31 10:37:29 by mariverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cgitems.h"

int	fillplayerdat(t_map *dat, int i, int j)
{
	dat->px = j;
	dat->py = i;
	dat->pdir = dat->raw[i][j];
	dat->raw[i][j] = '0';
	return (1);
}

void	fillplayer(t_map *dat)
{
	int	i;
	int	j;
	int	errorchk;

	i = 0;
	errorchk = 0;
	while (dat->raw[i])
	{
		j = 0;
		while (dat->raw[i][j])
		{
			if (dat->raw[i][j] == 'N' || dat->raw[i][j] == 'E'
				|| dat->raw[i][j] == 'S' || dat->raw[i][j] == 'W')
			{
				if (errorchk)
				{
					printf("multiples inicios para pj\n");
					exit(1);
				}
				errorchk = errorchk + fillplayerdat(dat, i, j);
			}
			j++;
		}
		i++;
	}
}

int	extractonecolor(char *c, unsigned int *i)
{
	int		res;
	char	color[8];

	res = 0;
	while (c[res] >= '0' && c[res] <= '9')
	{
		color[res] = c[res];
		res++;
	}
	color[res] = 0;
	*i = ft_atoi(color);
	if (*i > 255)
	{
		printf("color fuera de rango\n");
		exit (1);
	}
	return (res);
}

int	extractcolor(char *c)
{
	int				indic;
	unsigned int	colors[8];

	indic = 0;
	c++;
	while (*c)
	{
		if (*c == ' ' || *c == ',' || *c == '\n' || *c == '\t')
			c++;
		else if (*c >= '0' && *c <= '9')
			c = c + extractonecolor(c, &(colors[indic++]));
		else if (*c != '\0')
		{
			printf("caracter no permitido en la definicion de color %c\n", *c);
			exit (1);
		}
	}
	if (indic != 3)
	{
		printf("datos erroneos en la definicion de color\n");
		exit (1);
	}
	return ((colors[0] << 16) + (colors[1] << 8) + colors[2]);
}

void	fillcolors(t_map *dat, t_list *tl)
{
	while (tl)
	{
		if (identifyline(tl->content) == 5)
		{
			dat->fcolor = extractcolor(tl->content);
		}
		else if (identifyline(tl->content) == 6)
		{
			dat->ccolor = extractcolor(tl->content);
		}
		tl = tl->next;
	}
}
