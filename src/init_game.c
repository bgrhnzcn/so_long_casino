#include "so_long.h"

void init_img(t_game *casino)
{
	int x;
	int y;

	casino->img.imgs[0] = mlx_xpm_file_to_image(casino->m, "./xpm/red_bird.xpm", &x, &y);
	casino->img.imgs[1] = mlx_xpm_file_to_image(casino->m, "./xpm/red.xpm", &x, &y);
	casino->img.imgs[2] = mlx_xpm_file_to_image(casino->m, "./xpm/yellow_bird.xpm", &x, &y);
	casino->img.imgs[3] = mlx_xpm_file_to_image(casino->m, "./xpm/yellow.xpm", &x, &y);
	casino->img.imgs[4] = mlx_xpm_file_to_image(casino->m, "xpm/black_bird.xpm", &x, &y);
	casino->img.imgs[5]  = mlx_xpm_file_to_image(casino->m, "./xpm/black.xpm", &x, &y);
	casino->img.imgs[6] = mlx_xpm_file_to_image(casino->m, "./xpm/green_bird.xpm", &x, &y);
	casino->img.imgs[7] = mlx_xpm_file_to_image(casino->m, "./xpm/green.xpm", &x, &y);
	casino->img.imgs[8] = mlx_xpm_file_to_image(casino->m, "./xpm/background.xpm", &x, &y);

}

void casino_init(t_game *casino)
{
	casino->m = mlx_init();
	casino->mw = mlx_new_window(casino->m, 1600, 900, NAME);
	mapgen(casino);
	init_img(casino);
	print_map(casino);
}
