#ifndef CGSCREEN_H
# define CGSCREEN_H
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "mlx.h"

typedef struct cgimgdata
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		wide;
	int		tall;
}	t_imgdata;

typedef struct cgcolor
{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_cgcolor;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}	t_texture;

typedef struct cgscreen
{
	void		*mlx;
	void		*win;
	t_imgdata	*imgdata;
	t_cgcolor	*cgcolor;
	t_texture	*wall_textures[4];
	int			wide;
	int			tall;
}	t_cgscreen;

typedef struct intgroup
{
	int	x;
	int	y;
	int	color;
	int	ix;
	int	iy;
}	t_intgroup;

t_cgscreen	*initcgscreen(int w, int h);
void		endcgmlx(t_cgscreen *dat);
void		updatescreen(t_cgscreen *dat);

void		pixeltoimg(t_imgdata *data, int x, int y, int color);
void		sqaretoimg(t_imgdata *data, t_intgroup *tig, int sz);
void		fillscreenimg(t_cgscreen *m, int colorc, int colorf);
void		fillscreenimggrid(t_cgscreen *m, int line);

void		loadtextures(t_cgscreen *dat, char *files[4]);

void		paint3d(t_cgscreen *m, float *renderdata, int res);

void		printmapimg(t_imgdata *data, char **c, int scale);

t_texture	*load_texture(void *mlx, char *path);
void		free_texture(void *mlx, t_texture *tex);
int			get_pixel_color(t_texture *tex, float x, float y);
int			get_pixel_color2(t_texture *tex, int x, int y);

t_cgcolor	colorwhite(void);
t_cgcolor	colorblack(void);
t_cgcolor	colorred(void);
t_cgcolor	colorgreen(void);
t_cgcolor	colorblue(void);
int			colortoint(t_cgcolor *color);

#endif