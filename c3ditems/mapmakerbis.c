#include "cgitems.h"

void	fillplayer(t_map *dat)
{
	int	i;
	int	j;

	i = 0;
	while (dat->raw[i])
	{
		j = 0;
		while (dat->raw[i][j])
		{
			if (dat->raw[i][j] == 'N' || dat->raw[i][j] == 'E'
				|| dat->raw[i][j] == 'S' || dat->raw[i][j] == 'W')
			{
				dat->px = j;
				dat->py = i;
				dat->pdir = dat->raw[i][j];
				dat->raw[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}

int	extractcolor(char *c)
{
	int		i;
	int		indic;
	char	color[4];
	int		colors[3];

	indic = 0;
	while (*c && indic < 3)
	{
		i = 0;
		while (*c >= '0' && *c <= '9' && i < 3)
			color[i++] = *c++;
		if (i)
		{
			color[i] = 0;
			colors[indic++] = ft_atoi(color);
		}
		if (*c)
			c++;
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
