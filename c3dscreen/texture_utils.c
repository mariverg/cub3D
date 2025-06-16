#include "cgscreen.h"

// Obtiene el color de un píxel en (x,y) como entero ARGB
int get_pixel_color(t_texture *tex, int x, int y) {
    if (x < 0 || x >= tex->width || y < 0 || y >= tex->height)
        return 0x00000000; // Negro transparente si está fuera de límites

    int offset = y * tex->line_len + x * (tex->bpp / 8);
    return *(int *)(tex->addr + offset);
}

