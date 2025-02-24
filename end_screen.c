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

void ft_win(t_map *map)
{
    map->exit = 1;
    map->moves++;
    mlx_clear_window(map->mlx, map->wnd);
    mlx_string_put(map->mlx, map->wnd, map->x / 2 * IMG_PXL, map->y /2 * IMG_PXL, 0xFFFA9E, "GG YOU WON");
    write(1, "\n", 1);
    write(1, "\x1b[33;01m", 9);
    write(1, "🏆 YOU WON!! 🏆\n", 14);
    write(1, "\x1b[0m", 5);
    ft_close(map);
}