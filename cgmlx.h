#ifndef CGMLX
# define CGMLX
# include <stdlib.h>
# include "mlx.h"


typedef struct	t_imgdata {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		wide;
	int		tall;
}	s_imgdata;

typedef struct cgcolor {
	int	r;
	int	g;
	int	b;
	int	a;
}	s_cgcolor;

typedef struct cgmlx {
	void	*mlx;
	void	*win;
	s_imgdata	*imgdata;
	s_cgcolor	*cgcolor;
	int		wide;
	int		tall;
}	s_cgmlx;

s_cgmlx *initcgmlx(int w, int h);

void	pixeltoimg(s_imgdata *data, int x, int y, int color);
void	sqaretoimg(s_imgdata *data, int x, int y, int color, int sz);
void	paintmapimg(s_cgmlx *m, char	**raw, float sz);
void	fillscreenimg(s_cgmlx *m);
void	fillscreenimggrid(s_cgmlx *m, int line);
void	linetoimg(s_cgmlx *m, int xa, int ya, int xb, int yb);

void pixeltoscreen(s_cgmlx *m, int x, int y);
void sqaretosecreen(s_cgmlx *m, int x, int y);
void linetoscreen(s_cgmlx *m, int xa, int ya, int xb, int yb);
void fillscreen(s_cgmlx *m);
void paintmap(s_cgmlx *m, char	**raw, float sz);

s_cgcolor colorwhite();
s_cgcolor colorblack();
s_cgcolor colorred();
s_cgcolor colorgreen();
s_cgcolor colorblue();
int colortoint(s_cgcolor *color);

#endif