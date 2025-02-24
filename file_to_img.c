#include "so_long.h"

void file_to_img(t_map *map)
{
    int a;

    a = IMG_PXL;
    map->img.floor = mlx_xpm_file_to_image(map->mlx, "Ressources/floor.xpm", &a, &a);
    if (!map->img.floor)
        error_image(map);

    map->img.collectible = mlx_xpm_file_to_image(map->mlx, "Ressources/collectible.xpm", &a, &a);
    if (!map->img.collectible)
        error_image(map);

    map->img.wall = mlx_xpm_file_to_image(map->mlx, "Ressources/wall.xpm", &a, &a);
    if (!map->img.wall)
        error_image(map);

    map->img.player = mlx_xpm_file_to_image(map->mlx, "Ressources/player.xpm", &a, &a);
    if (!map->img.player)
        error_image(map);

    map->img.enemy = mlx_xpm_file_to_image(map->mlx, "Ressources/enemy.xpm", &a, &a);
    if (!map->img.enemy)
        error_image(map);
    map->img.exit = mlx_xpm_file_to_image(map->mlx, "Ressources/exit_active.xpm", &a, &a);
    if (!map->img.exit)
        error_image(map);
}


void error_image(t_map *map)
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
    ft_exit_free(map);
}