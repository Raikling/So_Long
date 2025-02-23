#include "so_long.h"

void check_file(t_map *map) //checks if the filename ends with ".ber"
{
    size_t len;

    len = ft_strlen(map->filename);
    if (map->filename[len - 1] != 'r')
        error_filename();
    if( map->filename[len - 2] != 'e')
        error_filename();
    if (map->filename[len - 3] != 'b')
        error_filename();
    if (map->filename[len - 4] != '.')
        error_filename();
    if (!ft_strnstr(map->filename, ".ber", ft_strlen(map->filename)))
        error_filename();
}

void check_param(t_map *map) //counts the number or C, E, P, then checks for their bare minimum
{
    int x;
    int y;

    x = 0;
    while (x < map->x)
    {
        y = 0;
        while (y < map->y)
        {
            if (map->array[x][y] == 'C')
                map->c++;
            else if (map->array[x][y] == 'E')
                map->e++;
            else if (map->array[x][y] == 'P')
                map->p++;
            else if (map->array[x][y] == '0' || map->array[x][y] == '1')
            ;
            else
                error_map_elements(map);
            y++;
        }
        y = 0;
        x++;
    }
    if (map->c < 1 || map->e < 1 || map->p != 1)
        error_map_elements(map);
}
void check_wall(t_map *map) //testing
{
    int x, y;
    y = 0;
    while (y < map->y)
    {
        if (map->array[0][y] != '1' || map->array[map->x - 1][y] != '1')
            error_wall(map);
        y++;
    }
    x = 1;
    while (x < map->x - 1)
    {
        if (map->array[x][0] != '1' || map->array[x][map->y - 1] != '1')
            error_wall(map);
        x++;
    }
}