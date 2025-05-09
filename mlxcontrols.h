#ifndef MLXCONTROLS
# define MLXCONTROLS
# include "mlx.h"


typedef struct cgmlx {
	void	*mlx;
	void	*win;
	int		wide;
	int		heigth;
}	s_cgmlx;

typedef struct cgcolor {
	int	r;
	int	g;
	int	b;
	int	a;
}	s_cgcolor;



s_cgmlx initcgmlx(int w, int h);
void pixeltoscreen(s_cgmlx *m, int x, int y);
void sqaretosecreen(s_cgmlx *m, int x, int y);
void linetoscreen(s_cgmlx *m, int xa, int ya, int xb, int yb);

s_cgcolor colorwhite();
s_cgcolor colorblack();
s_cgcolor colorred();
s_cgcolor colorgreen();
s_cgcolor colorblue();
int colortoint(s_cgcolor *color);

#endif