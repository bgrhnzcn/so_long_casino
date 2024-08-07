#include "so_long.h"


void put_image_to_map(t_game *casino)
{
	mlx_put_image_to_window(casino->m,casino->mw,casino->img.imgs[8], 0, 0);
	for (int y = 0; y < MAP_SIZE; y++)
	{
		for (int x = 0; x < MAP_SIZE; x++)
		{
			mlx_put_image_to_window(casino->m,
									casino->mw,
									casino->img.imgs[strchr(g_tiles, casino->map.map[y][x]) - g_tiles],
									400 + 100 * x ,
									50 + 100 * y);
		}
	}
}




void move_bird(t_game *casino, char bird)
{
	for (int y = 0; y < MAP_SIZE; y++)
	{
		for (int x = 0; x < MAP_SIZE; x++)
		{
			if ()
		}
	}
}

int	update(t_game *casino)
{


	put_image_to_map(casino);
}