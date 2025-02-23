#include "so_long.h"


void map_printer(t_map *map)
{
    int x;
    int y;

    x = 0;
    while (x < map->x)
    {
        y = 0;
        while (y < map->y)
        {
            if(map->array[x][y] == '1')
                mlx_put_image_to_window(map->mlx, map->wnd, map->img.wall, y * IMG_PXL, x * IMG_PXL);
            else if (map->array[x][y] == '0')
                mlx_put_image_to_window(map->mlx, map->wnd, map->img.floor, y * IMG_PXL, x * IMG_PXL);
            else if (map->array[x][y] == 'C')
                mlx_put_image_to_window(map->mlx, map->wnd, map->img.collectible, y * IMG_PXL, x * IMG_PXL);
            else if (map->array[x][y] == 'E')
                mlx_put_image_to_window(map->mlx, map->wnd, map->img.exit, y * IMG_PXL, x * IMG_PXL);
            else if (map->array[x][y] == 'P')
                mlx_put_image_to_window(map->mlx, map->wnd, map->img.player, y * IMG_PXL, x * IMG_PXL);
            y++;
        }
        x++;
    }
}