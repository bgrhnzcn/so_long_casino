#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx.h"

//#include "libft.h"
#include "ft_inputs.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

# define NAME "SO_LONG"
# define MAP_SIZE 8

// GREEN 0.1
// YELLOW 0.15
// RED 0.2
// BLACK 0.25

static const char	*g_birds = "GYRB";
static const char	*g_tiles = "RrYyBbGgE";

typedef enum e_bool
{
	error = -1,
	false,
	true
}	t_bool;

typedef struct s_slot{

	char **map;
}				t_slot;

typedef struct s_node {
	int y;
	int x;
	struct s_node *prev;
	struct s_node *next;
}				t_node;

typedef struct s_slot_img{
	void *imgs[10];
	void *black_bird;
	void *black_col;
	void *yellow_bird;
	void *yellow_col;
	void *green_bird;
	void *green_col;
	void *red_bird;
	void *red_col;
}				t_slot_img;

typedef struct s_bird{

	char	col;
	int		colcount;
	char	bird;
	int x;
	int	y;
	t_node *path;
	t_node *path_2;
}				t_bird;

typedef struct s_game{

	void *m;
	void *mw;

	t_bird bird;
	t_bool isplaying;
	t_slot map;
	t_slot_img img;
}				t_game;

// MAP
void mapgen(t_game *casino);
void print_map(t_game *casino);
char *randstring(size_t length);

// INIT
void casino_init(t_game *casino);
void init_img(t_game *casino);

// UPDATE	
void put_image_to_map(t_game *casino);
int	update(t_game *casino);
void	flood_fill(t_game *casino);

// LIST
void	ft_lstadd_front(t_node **lst, t_node *new);
void	ft_lstadd_back(t_node **lst, t_node *new);
t_node	*ft_lstlast(t_node *lst);
t_node *new_list(int x, int y);
void	ft_lstremove_back(t_node *lst);

#endif