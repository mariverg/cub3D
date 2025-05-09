#include "mlxcontrols.h"

s_cgmlx initcgmlx(int w, int h)
{
	s_cgmlx res;
	res.wide = w;
	res.heigth = h;

	res.mlx = mlx_init();
	res.win = mlx_new_window(res.mlx, res.wide, res.heigth, "Hola MiniLibX");
	return (res);
}