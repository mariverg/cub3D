#ifndef CGITEMS_H
# define CGITEMS_H
# include <stdlib.h>
# include <math.h> 
# include "libft.h"
# include "cgscreen.h"

typedef struct cgray
{
	float	vx;
	float	vy;
	float	hx;
	float	hy;
}	t_ray;

typedef struct cgvector
{
	float	x;
	float	y;
	float	dir;
}	t_vector;

typedef struct cgplayer
{
	t_vector	position;
	int			turning;
	int			moving;
	int			strifing;
	int			resolution;
	float		*renderdata;
}	t_player;

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
}	t_map;

void		filltextures(t_map *dat, t_list *tl);
t_map		*initmap(int fd);
void		endmap(t_map *dat);
t_list		*extractlines(int fd);
void		fillmap(t_map *dat, t_list *tl);
void		fillplayer(t_map *dat);
void		fillcolors(t_map *dat, t_list *tl);
void		emptymap(t_map *dat);
int			identifyline(char *c);
void		ft_error(char *msg);

t_player	*initplayer(float x, float y, char dir, int resolution);
void		endplayer(t_player *dat);
void		updateplayer(t_player *dat, char **map);

// float		castray(t_vector *p, float *x, float *y, char **map);
float		castrenderray(t_vector *p, float *cuad, float *dist, char **map);
float		getver(t_vector *p, float *x, float *y, int cicle);
float		gethor(t_vector *p, float *x, float *y, int cicle);
// int			validatemapstructure(char **map);
int			validatemaptile(char **map, int x, int y);
int			validatemap(t_map *map);
t_map		*ceromap(void);
// void		printmapdata(t_map *mp);

int			securemap(int x, int y, char **map);
#endif