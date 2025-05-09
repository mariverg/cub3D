#include <unistd.h>
#include "mlxcontrols.h"



int main()
{
	write(1, "hola\n", 5);
	s_cgmlx	mimlx = initcgmlx(800, 600);
	sqaretosecreen(&mimlx, 500, 500);
	linetoscreen(&mimlx, 100, 100, 500, 200);
	mlx_loop(mimlx.mlx);
	return (0);
}