/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapmaker.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariverg <mariverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:37:08 by mariverg          #+#    #+#             */
/*   Updated: 2025/07/31 10:37:09 by mariverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cgitems.h"

int	mpsize(t_list *tl)
{
	int	res;

	res = 0;
	while (tl)
	{
		if (identifyline(tl->content) == 7)
		{
			if (tl->next && identifyline(tl->next->content) != 7)
			{
				printf("error mapa truncado\n");
				exit(1);
			}
		}
		res++;
		tl = tl->next;
	}
	return (res);
}

void	fillmap(t_map *dat, t_list *tl)
{
	int	i;

	dat->maxy = mpsize(tl);
	if (!dat->maxy)
		return ;
	dat->raw = malloc(sizeof(char *) * (dat->maxy + 1));
	if (!dat->raw)
		return ;
	i = 0;
	while (tl)
	{
		if (identifyline(tl->content) == 7)
		{
			dat->raw[i] = ft_strdup(tl->content);
			i++;
		}
		tl = tl->next;
	}
	dat->raw[i] = 0;
}

void	emptymap(t_map *dat)
{
	int	i;

	i = 0;
	while (dat->raw[i])
	{
		free(dat->raw[i]);
		i++;
	}
	free(dat->raw);
}

int	identifyline(char *c)
{
	if (!c)
		return (0);
	while (*c == ' ' || *c == '\t')
		c++;
	if (ft_strncmp(c, "NO ", 3) == 0)
		return (1);
	else if (ft_strncmp(c, "SO ", 3) == 0)
		return (3);
	else if (ft_strncmp(c, "WE ", 3) == 0)
		return (4);
	else if (ft_strncmp(c, "EA ", 3) == 0)
		return (2);
	else if (ft_strncmp(c, "F ", 2) == 0)
		return (5);
	else if (ft_strncmp(c, "C ", 2) == 0)
		return (6);
	else if (ft_strncmp(c, "1", 1) == 0 || ft_strncmp(c, "0", 1) == 0)
		return (7);
	if (*c)
	{
		printf("errorline in .cub\n");
		exit(66);
	}
	return (0);
}

t_list	*extractlines(int fd)
{
	int		i;
	char	cont[1024];
	t_list	*milist;

	i = 0;
	milist = 0;
	while (read(fd, &cont[i], 1))
	{
		if (cont[i] == '\n')
		{
			cont[i] = 0;
			if (i > 0)
				ft_lstadd_back(&milist, ft_lstnew(ft_strdup(cont)));
			else
				ft_lstadd_back(&milist, ft_lstnew(ft_strdup(" ")));
			i = 0;
		}
		else
			i++;
	}
	cont[i] = 0;
	if (i > 0)
		ft_lstadd_back(&milist, ft_lstnew(ft_strdup(cont)));
	return (milist);
}
