#include "cgscreen.h"

// Obtiene el color de un píxel en (x,y) como entero ARGB
int get_pixel_color2(t_texture *tex, int x, int y) {
    if (x < 0 || x >= tex->width || y < 0 || y >= tex->height)
        return 0x00000000; // Negro transparente si está fuera de límites

    int offset = y * tex->line_len + x * (tex->bpp / 8);
	// if (offset < 100)
    	return *(int *)(tex->addr + offset);
	// return (255);
}

int get_pixel_color(t_texture *tex, float x, float y) {
    int	xscaled;
	int	yscaled;
	
	// return (255);
	if (x < 0 || x > 1 || y < 0 || y > 1)
        return 0x00000000; // Negro transparente si está fuera de límites
	xscaled = x * tex->width;
	yscaled = y * tex->height;
    int offset = yscaled * tex->line_len + xscaled * (tex->bpp / 8);
    return *(int *)(tex->addr + offset);
}

