#include <unistd.h>
#include <stdio.h>
#include "cub3d.h"

# define TILESIZE 31

void	paintplayer(s_game *game)
{
	float	hx;
	float	hy;
	float	vx;
	float	vy;
	float	horctn;
	float	verctn;

	pixeltoimg(game->cgmlx->imgdata, game->player->x * TILESIZE, game->player->y * TILESIZE, 255);
	horctn = gethorpoint(game->player, &hx, &hy);
	verctn = getverpoint(game->player, &vx, &vy);
	if(horctn > verctn)
		linetoimg(game->cgmlx, game->player->x * TILESIZE, game->player->y * TILESIZE, vx * TILESIZE, vy * TILESIZE);
	else
		linetoimg(game->cgmlx, game->player->x * TILESIZE, game->player->y * TILESIZE, hx * TILESIZE, hy * TILESIZE);
}

int render_next_frame(s_game *game)
{
	static int i = 1;
	if (i)
	{
		fillscreenimggrid(game->cgmlx, TILESIZE);
		displaceplayer(game->player);
		paintmapimg(game->cgmlx, game->map->raw, TILESIZE);
		paintplayer(game);
		mlx_put_image_to_window(game->cgmlx->mlx, game->cgmlx->win, game->cgmlx->imgdata->img, 0, 0);
		// i = 0;
	}
	return (0);
}

int	key_event(int keycode, s_game *game)
{
	if (keycode == 97)
	{
		game->player->dir = game->player->dir - 0.1f;
	}
	else if (keycode == 100)
	{
		game->player->dir = game->player->dir + 0.1f;
	}
	else if (keycode == 119)
	{
		game->player->speed = game->player->speed + 0.01f;
	}
	else if (keycode == 115)
	{
		game->player->speed = game->player->speed - 0.01f;
	}
	// printf("Hello from key_hook %i!\n", keycode);
	return (0);
}

int mouse_event(int button, int x, int y, s_game *game)
{
	// printf("Hello from mouse %i!\n", button);

	sqaretoimg(game->cgmlx->imgdata, x, y, 255, 5);
	mlx_put_image_to_window(game->cgmlx->mlx, game->cgmlx->win, game->cgmlx->imgdata->img, 0, 0);

	// if (game->cgmlx->mlx)
	// 	sqaretosecreen(game->cgmlx, x, y);
	return (0);
}

int main()
{
	s_game	game;

	game.cgmlx = initcgmlx(800, 800);
	game.player = newplayer(1,1,0);
	game.map = demomap();

	mlx_key_hook(game.cgmlx->win, &key_event, &game);
	mlx_mouse_hook(game.cgmlx->win, &mouse_event, &game);
	mlx_loop_hook(game.cgmlx->mlx, &render_next_frame, &game);
	mlx_loop(game.cgmlx->mlx);
	return (0);
}