#include "so_long.h"




int main()
{
	t_game casino;

	casino_init(&casino);
	put_image_to_map(&casino);
	mlx_loop(casino.m);
	mlx_loop_hook(casino.m, update, &casino);

}