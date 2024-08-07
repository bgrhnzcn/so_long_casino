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
	if (f_fill(casino, map,y,y - 1,x,x, path, col) == 0)
		ft_lstremove_back(path);
	if (f_fill(casino, map, y, y + 1, x, x, path, col) == 0)
		ft_lstremove_back(path);
	if (f_fill(casino, map, y, y, x, x + 1, path, col) == 0)
		ft_lstremove_back(path);
	if (f_fill(casino, map, y, y, x, x - 1, path, col) == 0)
		ft_lstremove_back(path);
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

char **temp_map_f(char **map);
{
    char **temp_map;

	for (int x = 0; x < MAP_SIZE; x++)
		temp_map[x] = strndup(map[x], MAP_SIZE);
	print_map(temp_map);
    return (temp_map);
}

void p_map(char **temp_map)
{
	for (int x= 0; temp_map[x];x++)
		printf("%s\n",temp_map[x]);
}

void	flood_fill(t_game *casino)
{
    char **temp_map;
	t_node	*path;

	path = new_list(0, 0);
    temp_map = temp_map_f(casino->map.map);
    f_fill(file, temp_map, file->p.y, file->p.x);
    freepchar(temp_map);
}