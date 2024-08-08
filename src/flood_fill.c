#include "so_long.h"

int	f_fill(t_game *casino, char **map,size_t y_prev, size_t y, size_t x_prev, size_t x, t_node *path, char col)
{
	if (y < 0 || x < 0)
		return (0);
	if (y >= MAP_SIZE - 1 || x >= MAP_SIZE - 1)
		return (0);
	if (map[y][x] != col && map[y][x] != 'E' && map[y][x] != 'X')
		return (0);
	map[y][x] = 'X';
	ft_lstadd_back(&path, new_list(x - x_prev, y - y_prev));
	if (map[y][x] == col)
		return (1);
	printf("T - y:%i x:%i\n",path->y, path->x);
	if (f_fill(casino, map,y,y - 1,x,x, path, col) == 0)
		ft_lstremove_back(path);
	if (f_fill(casino, map, y, y + 1, x, x, path, col) == 0)
		ft_lstremove_back(path);
	if (f_fill(casino, map, y, y, x, x + 1, path, col) == 0)
		ft_lstremove_back(path);
	if (f_fill(casino, map, y, y, x, x - 1, path, col) == 0)
		ft_lstremove_back(path);
}

char **temp_map_f(char map[8][8], char ***tmp)
{
    char **temp_map;
	int a;

	temp_map = malloc(sizeof(char ) * MAP_SIZE + 1);
	for (int y = 0; y < MAP_SIZE; y++)
	{
		temp_map[y] = malloc(sizeof(char) * MAP_SIZE + 1);
		a = 0;
		for (int x = 0; x < MAP_SIZE; x++)
		{
			temp_map[y][x] = map[y][x];
			a++;
		}
		temp_map[y][a] = '\0';
	}
	*tmp = temp_map;
}

void p_map(char **temp_map)
{
	for (int x= 0; temp_map[x];x++)
		printf("%s\n",temp_map[x]);
}
void freepchar(char **str)
{
    size_t i;

    i = 0;
    if (!str)
        return ;
    while (str[i])
    {
        free(str[i]);
        str[i] = NULL;
        i++;
    }
    if (str)
        free(str);
    str = NULL;
}
void	flood_fill(t_game *casino)
{
    char **temp_map;

	casino->bird.path = new_list(0, 0);
	temp_map_f(casino->map.map, &temp_map);
    f_fill(casino, temp_map, \
	casino->bird.y, casino->bird.y ,casino->bird.x, \
	casino->bird.x,casino->bird.path, casino->bird.col);
}

