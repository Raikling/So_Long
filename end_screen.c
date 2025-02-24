#include "so_long.h"

int ft_close(t_map *map)
{
    if (map->img.floor)
        mlx_destroy_image(map->mlx, map->img.floor);
    if (map->img.collectible)
        mlx_destroy_image(map->mlx, map->img.collectible);
    if (map->img.wall)
        mlx_destroy_image(map->mlx, map->img.wall);
    if (map->img.player)
        mlx_destroy_image(map->mlx, map->img.player);
    if (map->img.enemy)
        mlx_destroy_image(map->mlx, map->img.enemy);
    if (map->img.exit)
        mlx_destroy_image(map->mlx, map->img.exit);

    if (map->wnd)
        mlx_destroy_window(map->mlx, map->wnd);
    map->wnd = NULL;

    ft_free_array(map->array, map->x);
    ft_free_array(map->copy, map->x);

    if (map->mlx)
    {
        mlx_destroy_display(map->mlx);
        free(map->mlx);
        map->mlx = NULL;
    }
    
    exit(EXIT_SUCCESS);
}