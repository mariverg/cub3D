#ifndef CGMAP
# define CGMAP

# include <stdlib.h>

typedef struct t_map
{
	char	**raw;
	float	lsize;
}	s_map;

s_map	*demomap();

#endif