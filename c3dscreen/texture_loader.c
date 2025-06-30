#include "cgscreen.h"

t_texture	*load_texture(void *mlx, char *path)
{
	t_texture	*tex;

	tex = malloc(sizeof(t_texture));
	if (!tex)
	{
		printf("memory fail\n");
		exit(1);
	}
	tex->img = mlx_xpm_file_to_image(mlx, path, &tex->width, &tex->height);
	if (!tex->img)
	{
		printf("error loading texture\n");
		free(tex);
		exit(0);
	}
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp,
			&tex->line_len, &tex->endian);
	return (tex);
}

void	loadtextures(t_cgscreen *dat, char *files[4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		dat->wall_textures[i] = load_texture(dat->mlx, files[i]);
		if (!dat->wall_textures[i])
			printf("Failed to load EA texture");
		i++;
	}
}

void	free_texture(void *mlx, t_texture *tex)
{
	if (tex)
	{
		if (tex->img)
			mlx_destroy_image(mlx, tex->img);
		free(tex);
	}
}
