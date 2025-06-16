#include "cgscreen.h"

// Carga una textura desde un archivo XPM
t_texture *load_texture(void *mlx, char *path) {
    t_texture *tex = malloc(sizeof(t_texture));
    if (!tex) return NULL;

    tex->img = mlx_xpm_file_to_image(mlx, path, &tex->width, &tex->height);
    if (!tex->img) {
        free(tex);
        return NULL;
    }

    tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->line_len, &tex->endian);
    return tex;
}

// Libera una textura
void free_texture(void *mlx, t_texture *tex) {
    if (tex) {
        if (tex->img) 
            mlx_destroy_image(mlx, tex->img);
        free(tex);
    }
}