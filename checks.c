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



void check_size(t_map *map)
{
    int x, row_len, max;

    if (map->x == 0 || !map->array || !map->array[0])
        error_size(map);
    x = 0;
    max = ft_strlen(map->array[0]);
    while (x < map->x)
    {
        if (!map->array[x])
            error_size(map);
        row_len = ft_strlen(map->array[x]);
        if (max != row_len)
            error_size(map);
        x++;
    }
    map->y = max;
}

// void map_checker(t_map *map)
// {
//     check_file(map);
//     map_array(map); 
//     check_size(map);
//     check_wall(map);
//     check_param(map);
//     //check_valid_path(map);
//     ft_free_array(map->copy, map->x);
    
// }

void map_checker(t_map *map)
{
    printf("Checking file...\n");
    check_file(map);
    printf("Parsing map...\n");
    map_array(map);
    printf("Checking size...\n");
    check_size(map);
    printf("Checking walls...\n");
    check_wall(map);
    printf("Checking elements...\n");
    check_param(map);
    printf("Map valid!\n");
    //ft_free_array(map->copy, map->x);
}