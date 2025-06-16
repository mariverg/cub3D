#ifndef CGSCREEN
# define CGSCREEN
# include <stdlib.h>
# include <math.h>
# include "mlx.h"


typedef struct	cgimgdata {
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

typedef struct cgscreen {
	void	*mlx;
	void	*win;
	s_imgdata	*imgdata;
	s_cgcolor	*cgcolor;
	int		wide;
	int		tall;
}	s_cgscreen;

typedef struct s_texture {
    void    *img;       // Puntero a la imagen de miniLibX
    char    *addr;      // Datos de píxeles
    int     width;      // Ancho de la imagen
    int     height;     // Alto de la imagen
    int     bpp;        // Bits por píxel
    int     line_len;   // Bytes por línea de imagen
    int     endian;     // Orden de bytes
} t_texture;

s_cgscreen	*initcgscreen(int w, int h);
void	endcgmlx(s_cgscreen *dat);
void	updatescreen(s_cgscreen *dat);

void	pixeltoimg(s_imgdata *data, int x, int y, int color);
void	sqaretoimg(s_imgdata *data, int x, int y, int color, int sz);
void	paraleltoimg(s_imgdata *data, int xa, int ya, int color, int xb, int yb);
void	paintmapimg(s_cgscreen *m, char	**raw, float sz);
void	fillscreenimg(s_cgscreen *m, int colorc, int colorf);
void	fillscreenimggrid(s_cgscreen *m, int line);
void	linetoimg(s_cgscreen *m, int xa, int ya, int xb, int yb);

void	paint3d(s_cgscreen *m, float *renderdata, int res);

void	printmapimg(s_imgdata *data, char **c, int scale);

t_texture *load_texture(void *mlx, char *path);
void free_texture(void *mlx, t_texture *tex);
int get_pixel_color(t_texture *tex, int x, int y);

s_cgcolor colorwhite();
s_cgcolor colorblack();
s_cgcolor colorred();
s_cgcolor colorgreen();
s_cgcolor colorblue();
int colortoint(s_cgcolor *color);

#endif