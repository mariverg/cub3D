#include "cub3d.h"

void paint_textured_column(s_cgscreen *screen, t_texture *tex, 
                          int screen_x, int wall_height, int tex_x) {
    for (int y = 0; y < wall_height; y++) {
        int tex_y = (y * tex->height) / wall_height;
        int color = get_pixel_color(tex, tex_x, tex_y);
        pixeltoimg(screen->imgdata, screen_x, y, color);
    }
}

/*int get_texture_color(t_texture *tex, float x, float y)
{
	int	color;
	int	xscaled;
	int yscaled;

	xscaled = x * tex->width;
	yscaled = y * tex->height;
	color = get_pixel_color(tex, xscaled, yscaled);
	return (color);
}*/