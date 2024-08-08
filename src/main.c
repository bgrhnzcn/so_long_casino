#include "so_long.h"


void deneme(int keycode, t_game *casino)
{
	if (keycode == 13)
	{
		update(casino);
	}
	else if (keycode == 1)
	{
		mapgen(casino);
		put_image_to_map(casino);
	}
	else if (keycode == 2)
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
	if (keycode == 53)
		exit(1);
}


int main()
{
	t_game casino;

	casino_init(&casino);
	put_image_to_map(&casino);
	mlx_hook(casino.mw, 2, 0, deneme, &casino);
	mlx_loop(casino.m);
}