#include "so_long.h"

int deneme(int keycode, t_game *casino)
{
	if (keycode == ESC_KEY)
		exit(1);
	if (keycode == 13)
	{
		update(casino);
	}
	else if (keycode == S_KEY)
	{
		mapgen(casino);
		put_image_to_map(casino);
	}
	else if (keycode == D_KEY)
	{
		t_node *temp;
		flood_fill(casino);
		temp = casino->bird.path;
		printf("BİRD:%c \n",casino->bird.bird);
		while (temp)
		{
			printf("x: %i, y: %i\n",temp->x, temp->y);
			temp = temp->next;
		}
	}
}

int main()
{
	t_game casino;

	casino_init(&casino);
	put_image_to_map(&casino);
	mlx_hook(casino.mw, KeyPress, (1 << 0), deneme, &casino);
	mlx_loop(casino.m);
}