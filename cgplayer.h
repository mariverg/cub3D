#ifndef CGPLAYER
# define CGPLAYER

# include <stdlib.h>
# include <math.h>
 
typedef struct t_player
{
	float	x;
	float	y;
	float	dir;
	float	speed;
}	s_player;

s_player	*newplayer(int x, int y, float dir);
void	displaceplayer(s_player *p);
void	moveplayer(s_player *p, float x, float y);
void	getpathpoint(s_player *p, float len, float *x, float *y);
void	getverpoint(s_player *p, float len, float *x, float *y);
void	gethorpoint(s_player *p, float len, float *x, float *y);

#endif