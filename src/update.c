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


void init_bird(t_game *casino, int y, int x)
{
	casino->bird.bird = casino->map.map[y][x];
	casino->bird.col = casino->map.map[y][x] + 32;
	casino->bird.colcount = 0;
	casino->bird.x = x;
	casino->bird.y = y;
}

void move_bird(t_game *casino, t_bird *bird)
{
	while (1)
	{
		if (bird->x + 1 < MAP_SIZE && casino->map.map[bird->y][bird->x + 1] == bird->col)
		{
			while (bird->x + 1 < MAP_SIZE && casino->map.map[bird->y][bird->x + 1] == bird->col)
			{
				casino->map.map[bird->y][bird->x] = 'E';
				bird->x++;
			}
			casino->map.map[bird->y][bird->x] = casino->bird.bird;
		}
		else if (bird->x - 1 >= 0 && casino->map.map[bird->y][bird->x - 1] == bird->col)
		{
			while (bird->x - 1 >= 0 && casino->map.map[bird->y][bird->x - 1] == bird->col)
			{
				casino->map.map[bird->y][bird->x] = 'E';
				bird->x--;
			}
			casino->map.map[bird->y][bird->x] = casino->bird.bird;
		}
		else if (bird->y + 1 < MAP_SIZE && casino->map.map[bird->y + 1][bird->x] == bird->col)
		{
			while (bird->y + 1 < MAP_SIZE && casino->map.map[bird->y + 1][bird->x] == bird->col)
			{
				casino->map.map[bird->y][bird->x] = 'E';
				bird->y++;
			}
			casino->map.map[bird->y][bird->x] = casino->bird.bird;
		}
		else if (bird->y - 1 >= 0 && casino->map.map[bird->y - 1][bird->x] == bird->col)
		{
			while (bird->y - 1 >= 0 && casino->map.map[bird->y - 1][bird->x] == bird->col)
			{
				casino->map.map[bird->y][bird->x] = 'E';
				bird->y--;
			}
			casino->map.map[bird->y][bird->x] = casino->bird.bird;
		}
		else
			break;
	}
}


void find_bird(t_game *casino)
{
	for (int y = 0; y < MAP_SIZE; y++)
	{
		for (int x = 0; x < MAP_SIZE; x++)
		{
			if (strchr(g_birds, casino->map.map[y][x]))
			{	
				init_bird(casino, y, x);
				move_bird(casino, &casino->bird);
			}
		}
	}
}

int	update(t_game *casino)
{
	find_bird(casino);
	put_image_to_map(casino);
}