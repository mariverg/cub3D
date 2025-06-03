#ifndef CGITEMS
# define CGITEMS
# include <stdlib.h>
# include <math.h> 
# include "libft.h"

typedef struct cgray
{
	float	vx;
	float	vy;
	float	hx;
	float	hy;
}	s_ray;

typedef struct cgvector
{
	float	x;
	float	y;
	float	dir;
}	s_vector;

typedef struct cgplayer
{
	s_vector	position;
	int			turning;
	int			moving;
	int			resolution;
	float		*renderdata;
}	s_player;

typedef struct cgmap
{
	int		px;
	int		py;
	char	pdir;
	char	*textures[4];
	int		fcolor;
	int		ccolor;
	char	**raw;
	int		maxy;
}	s_map;

s_map	*initmap(int fd);
void	endmap(s_map *dat);
t_list	*extractlines(int fd);
void	fillmap(s_map *dat, t_list *tl);
void	fillplayer(s_map *dat);
void	fillcolors(s_map *dat, t_list *tl);
void	filltextures(s_map *dat, t_list *tl);
void	emptymap(s_map *dat);
int 	identifyline(char *c);

s_player	*initplayer(float x, float y, char dir, int resolution);
void		endplayer(s_player *dat);
void		updateplayer(s_player *dat, char **map);

float	castray(s_vector *p, float *x, float *y, char **map);
void	printmapdata(s_map *mp);
#endif