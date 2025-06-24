#ifndef CGITEMS
# define CGITEMS
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
	int			strifing;
	int			resolution;
	float		*renderdata;
}	s_player;

typedef struct cgmap
{
	int		px;
	int		py;
	char	pdir;
	// t_texture *wall_textures[4];
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
// void	filltextures2(s_map *dat, t_list *tl, void *mlx_ptr);
void	emptymap(s_map *dat);
int 	identifyline(char *c);
void ft_error(char *msg);

s_player	*initplayer(float x, float y, char dir, int resolution);
void		endplayer(s_player *dat);
void		updateplayer(s_player *dat, char **map);

float	castray(s_vector *p, float *x, float *y, char **map);
float	castrenderray(s_vector *p, float *cuad, float *dist, char **map);
void	printmapdata(s_map *mp);
#endif