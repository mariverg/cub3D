#include "cgitems.h"

char	*extractroute(char *c)
{
	c += 2;
	while (*c)
	{
		if (*c == ' ' || *c == '\t')
			c++;
		else
			return (ft_strdup(c));
	}
	return (0);
}

void	filltextures(t_map *dat, t_list *tl)
{
	while (tl)
	{
		if (identifyline(tl->content) == 1)
		{
			dat->textures[0] = extractroute(tl->content);
		}
		else if (identifyline(tl->content) == 2)
		{
			dat->textures[1] = extractroute(tl->content);
		}
		else if (identifyline(tl->content) == 3)
		{
			dat->textures[2] = extractroute(tl->content);
		}
		else if (identifyline(tl->content) == 4)
		{
			dat->textures[3] = extractroute(tl->content);
		}
		tl = tl->next;
	}
}

void	ft_error(char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}
