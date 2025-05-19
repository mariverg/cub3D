#ifndef CUB3D
# define CUB3D

#include "cgmlx.h"
#include "cgplayer.h"
#include "cgmap.h"

typedef struct t_game
{
	s_cgmlx		*cgmlx;
	s_player	*player;
	s_map		*map;
}	s_game;

#endif