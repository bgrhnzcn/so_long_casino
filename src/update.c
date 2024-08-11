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
									casino->img.imgs[strchr(g_tiles, casino->map[y][x]) - g_tiles],
									400 + 100 * x ,
									50 + 100 * y);
		}
	}
}


void init_bird(t_game *casino, int y, int x)
{
	casino->bird.bird = casino->map[y][x];
	casino->bird.col = casino->map[y][x] + 32;
	casino->bird.colcount = 0;
	casino->bird.x = x;
	casino->bird.y = y;
}

void move_bird(t_game *casino, t_bird *bird)
{
	while (1)
	{
		if (bird->x + 1 < MAP_SIZE && casino->map[bird->y][bird->x + 1] == bird->col)
		{
			while (bird->x + 1 < MAP_SIZE && casino->map[bird->y][bird->x + 1] == bird->col)
			{
				casino->map[bird->y][bird->x] = 'E';
				bird->x++;
			}
			casino->map[bird->y][bird->x] = casino->bird.bird;
		}
		else if (bird->x - 1 >= 0 && casino->map[bird->y][bird->x - 1] == bird->col)
		{
			while (bird->x - 1 >= 0 && casino->map[bird->y][bird->x - 1] == bird->col)
			{
				casino->map[bird->y][bird->x] = 'E';
				bird->x--;
			}
			casino->map[bird->y][bird->x] = casino->bird.bird;
		}
		else if (bird->y + 1 < MAP_SIZE && casino->map[bird->y + 1][bird->x] == bird->col)
		{
			while (bird->y + 1 < MAP_SIZE && casino->map[bird->y + 1][bird->x] == bird->col)
			{
				casino->map[bird->y][bird->x] = 'E';
				bird->y++;
			}
			casino->map[bird->y][bird->x] = casino->bird.bird;
		}
		else if (bird->y - 1 >= 0 && casino->map[bird->y - 1][bird->x] == bird->col)
		{
			while (bird->y - 1 >= 0 && casino->map[bird->y - 1][bird->x] == bird->col)
			{
				casino->map[bird->y][bird->x] = 'E';
				bird->y--;
			}
			casino->map[bird->y][bird->x] = casino->bird.bird;
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
			if (strchr(g_birds, casino->map[y][x]))
			{	
				init_bird(casino, y, x);
				move_bird(casino, &casino->bird);
			}
		}
	}
}

int ft_bird_path_size(t_node *path)
{
	int i;
	t_node *node;

	node = path;
	i = 0;
	while (node)
	{
		i++;
		node = node->next;
	}
	return (i);
}

void bird_next_move(t_game *casino, t_bird *bird, t_node *path)
{
	t_node *temp;

	printf("a\n");
	temp = path;
	while (temp)
	{
		casino->map[bird->y][bird->x] = 'E';
		bird->y += temp->y;
		bird->x += temp->x;
		put_image_to_map(casino);
		sleep(2);
		temp = temp->next;
	}
}

void set_next_bird(t_game *casino)
{
	int path_1 = ft_bird_path_size(casino->bird.path_1);
	int path_2= ft_bird_path_size(casino->bird.path_2);
	int path_3 = ft_bird_path_size(casino->bird.path_3);
	int path_4 = ft_bird_path_size(casino->bird.path_4);

	printf("%i %i %i %i\n",path_1,path_2,path_3,path_4);
	if (path_1 > path_2 && path_1 > path_3 && path_1 > path_4)
	{
		bird_next_move(casino, &casino->bird, casino->bird.path_1);
	}
	if (path_2 > path_1 && path_2 > path_3 && path_2 > path_4)
	{
bird_next_move(casino, &casino->bird, casino->bird.path_2);
	}
	if (path_3 > path_2 && path_3 > path_1 && path_3 > path_4)
	{
bird_next_move(casino, &casino->bird, casino->bird.path_3);
	}
	if (path_4 > path_2 && path_4 > path_3 && path_4 > path_1)
	{
bird_next_move(casino, &casino->bird, casino->bird.path_4);
	}
}


int	update(t_game *casino)
{
	find_bird(casino);
	put_image_to_map(casino);
}

int	update_next(t_game *casino)
{
	printf("Update_next\n");
	set_next_bird(casino);
	put_image_to_map(casino);
}