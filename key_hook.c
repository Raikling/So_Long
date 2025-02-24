#include "so_long.h"

void scan_player(t_map *map)
{
    map->player.x = 0;
    map->player.y = 0;

    while(map->player.x < map->x)
    {
        while (map->player.y < map->y)
        {
            if (map->array[map->player.x][map->player.y] == 'P')
                break;
            map->player.y++;
        }
        if (map->array[map->player.x][map->player.y] == 'P')
            break;
        map->player.y = 0;
        map->player.x++;
    }
}

int key_hook(int keysym, t_map *map)
{
    scan_player(map);
    if(keysym == ESC)
        return(ft_close(map));
    else if (keysym == UP)
        move_up(map);
    else if (keysym == DOWN)
        move_down(map);
    else if (keysym == RIGHT)
        move_right(map);
    else if (keysym == LEFT)
        move_left(map);    
    return (0);
}