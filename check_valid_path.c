#include "so_long.h"

void move_on_path(t_map *map, int x, int y)
{
    if (x < 0 || x >= map->x || y < 0 || y >= map->y)
        return ;
    char type;

    type = map->copy[x][y];
    if (type == 'C')
    {
        map->c_check -= 1;
        map->copy[x][y] = '1';
    }
    else if (type == 'E')
    {
        map->e_check -= 1;
        map->copy[x][y] = '1';
        return ;
    }
    else if (type == '0' || type == 'P')
        map->copy[x][y] = '1';
    else if (type == '1')
        return ;    
    else 
        return ;
    move_on_path(map, x + 1, y);
    move_on_path(map, x - 1, y);
    move_on_path(map, x, y + 1);
    move_on_path(map, x, y - 1);
}


void check_valid_path(t_map *map)
{
    map->c_check = map->c;
    map->e_check = map->e;
    scan_player(map);
    move_on_path(map, map->player.x, map->player.y);
    if (map->c_check != 0 || map->e_check != 0)
    {
        ft_printf("\033[1;31m🛑ERROR: NO VALID PATH\n\033[0m");
        ft_free_array(map->array, map->x);
        ft_free_array(map->copy, map->x);
        exit(EXIT_FAILURE);
    }

}
