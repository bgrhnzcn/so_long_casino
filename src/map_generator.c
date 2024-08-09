#include "so_long.h"

char *randstring(size_t length)
{

    static char charset[] = "ybrg";
    char *randomString = NULL;
    if (length) {
        randomString = malloc(sizeof(char) * (length +1));

        if (randomString) 
		{
            for (size_t n = 0;n < length;n++) 
			{
                int key = rand() % (int)(sizeof(charset) -1);
                randomString[n] = charset[key];
            }
            randomString[length] = '\0';
        }
    }

    return randomString;
}

void print_map(t_game *casino)
{
	for (int x = 0; x < MAP_SIZE; x++)
	{
		for (int c = 0; c < MAP_SIZE; c++)
			printf("%c",casino->map.map[x][c]);
		printf("\n");
	}
}



void mapgen(t_game *casino)
{
	int x;
	int y;
	int a;
	int k;

	k = 0;
	casino->map.map = malloc(sizeof(char *) * MAP_SIZE + 1);
	while (k < MAP_SIZE)
	{
		casino->map.map[k] = strdup(randstring(MAP_SIZE));
		k++;
	}
	casino->map.map[k] = NULL;
	a = 0;
	while (1)
	{
		x = rand() % 8;
		y = rand() % 8;
		if (!strchr(g_birds, casino->map.map[y][x]))
			casino->map.map[y][x] = g_birds[a++];
		if (a == 4)
			break;
	}
}