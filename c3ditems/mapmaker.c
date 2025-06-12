#include "cgitems.h"
// #include <unistd.h>

void	printmapdata(s_map *mp)
{
	char	*aux;

	write(1,"player ",7);
	aux = ft_itoa(mp->px);
	write(1,aux,ft_strlen(aux));
	free(aux);
	write(1," ",1);
	aux = ft_itoa(mp->py);
	write(1,aux,ft_strlen(aux));
	free(aux);
	write(1," ",1);
	write(1, &(mp->pdir), 1);
	write(1,"\n",1);

	write(1,"colors ",7);
	aux = ft_itoa(mp->fcolor);
	write(1,aux,ft_strlen(aux));
	free(aux);
	write(1," ",1);
	aux = ft_itoa(mp->ccolor);
	write(1,aux,ft_strlen(aux));
	free(aux);
	write(1,"\n",1);

	write(1,"textures\n",9);
	write(1,mp->textures[0],ft_strlen(mp->textures[0]));
	write(1," ",1);
	write(1,mp->textures[1],ft_strlen(mp->textures[1]));
	write(1," ",1);
	write(1,mp->textures[2],ft_strlen(mp->textures[2]));
	write(1," ",1);
	write(1,mp->textures[3],ft_strlen(mp->textures[3]));
	write(1,"\n",1);
	
	char **c = mp->raw;
	while (*c)
	{
		write(1, *c, ft_strlen(*c));
		write(1, "\n", 1);
		c++;
	}
}

int mpsize(t_list *tl)
{
	int res;

	res = 0;
	while (tl)
	{
		if (identifyline(tl->content) == 7)
			res++;
		tl = tl->next;
	}
	return (res);
}

void	fillmap(s_map *dat, t_list *tl)
{
	int i;

	dat->maxy = mpsize(tl);
	if (!dat->maxy)
		return ;
	dat->raw = malloc(sizeof(char *) * (dat->maxy + 1));
	if (!dat->raw)
		return ;
	i = 0;
	while (tl)
	{
		if(identifyline(tl->content) == 7)
		{
			dat->raw[i] = ft_strdup(tl->content);
			i++;
		}
		tl = tl->next;
	}
	dat->raw[i] = 0;
}

void	emptymap(s_map *dat)
{
	int i;

	i = 0;
	while (dat->raw[i])
	{
		free(dat->raw[i]);
		i++;
	}
	free(dat->raw);
}

int identifyline(char *c)
{
	if (!c)
		return (0);
	while (*c == ' ' || *c == '\t')
		c++;
	if (ft_strncmp(c, "NO ", 3) == 0)
		return (1);
	else if (ft_strncmp(c, "SO ", 3) == 0)
		return (3);
	else if (ft_strncmp(c, "EA ", 3) == 0)
		return (2);
	else if (ft_strncmp(c, "WE ", 3) == 0)
		return (4);
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

	int i;
	char	cont[1024];
	t_list	*milist;
	char *aux;
	char *c;

	i = 0;
	milist = 0;
	while (read(fd, &cont[i], 1))
	{
		if (cont[i] == '\n')
		{
			cont[i] = 0;
			if (i > 0)
				ft_lstadd_back(&milist, ft_lstnew(ft_strdup(cont)));
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

void	fillplayer(s_map *dat)
{
	int i;
	int	j;

	i = 0;
	while(dat->raw[i])
	{
		j = 0;
		while(dat->raw[i][j])
		{
			if(dat->raw[i][j] == 'N' || dat->raw[i][j] == 'E' || dat->raw[i][j] == 'S' || dat->raw[i][j] == 'W')
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
	int i;
	int indic;
	char color[4];
	int colors[3];

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

void fillcolors(s_map *dat, t_list *tl)
{
	int micolor;

	while (tl)
	{
		if(identifyline(tl->content) == 5)
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

char	*extractroute(char *c)
{
	c+=2;
	while(*c)
	{
		if(*c == ' ' || *c == '\t')
			c++;
		else
			return (ft_strdup(c));
	}
}

void filltextures(s_map *dat, t_list *tl)
{
	while (tl)
	{
		if(identifyline(tl->content) == 1)
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