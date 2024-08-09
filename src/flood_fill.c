#include "so_long.h"

int	f_fill(t_game *casino, char **map,size_t y_prev, size_t y, size_t x_prev, size_t x, t_node *path, t_node *path_2, char col)
{
	if (y < 0 || x < 0)
		return (0);
	if (y >= MAP_SIZE || x >= MAP_SIZE)
		return (0);
	if ((map[y][x] != col && map[y][x] != casino->bird.bird) && (map[y][x] != 'E' && map[y][x] != 'X'))
		return (0);
	if (map[y][x] == 'X')
		return (5);
	if (y - y_prev != 0 || x - x_prev != 0)
		ft_lstadd_back(&path_2, new_list(x - x_prev, y - y_prev));
	map[y][x] = 'X';
	ft_lstadd_back(&path, new_list(x - x_prev, y - y_prev));
	if (map[y][x] == col)
		return (1);
	f_fill(casino, map,y,y - 1,x,x, path, path_2, col);
	f_fill(casino, map, y, y + 1, x, x, path, path_2, col);
	f_fill(casino, map, y, y, x, x + 1, path, path_2, col);
	f_fill(casino, map, y, y, x, x - 1, path, path_2, col);
}

char **temp_map_f(char **map, char ***tmp)
{
    char **temp_map;
	int a;
	int c = 0;

	temp_map = malloc(sizeof(char ) * MAP_SIZE + 1);
	for (int y = 0; y < MAP_SIZE; y++)
	{
		temp_map[y] = strdup(map[y]);
		c++;
	}
	temp_map[c] = NULL;
	*tmp = temp_map;
}

void p_map(char **temp_map)
{
	for (int x= 0; temp_map[x];x++)
		printf("%s - X:%i\n",temp_map[x], x);
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
	casino->bird.path_2 = new_list(0, 0);
	temp_map_f(casino->map.map, &temp_map);
    f_fill(casino, temp_map, \
	casino->bird.y, casino->bird.y ,casino->bird.x, \
	casino->bird.x,casino->bird.path,casino->bird.path_2, casino->bird.col);
	while (casino->bird.path_2)
	{
		printf("B:%c y:%i x:%i\n",casino->bird.bird,casino->bird.path_2->y,casino->bird.path_2->x);
		casino->bird.path_2 = casino->bird.path_2->next;
	}
	printf("FLOOD_BİTTİ\n");
}

