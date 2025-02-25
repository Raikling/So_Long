#include "so_long.h"

void map_init(t_map *map, char **av)
{
    map->filename = av[1];
    map->moves = 0;
    map->e = 0;
    map->c = 0;
    map->p = 0;
    map->x = 0;
    map->player.x = 0;
    map->player.y = 0;
    map->exit = 0;
    map->array = NULL;
    map->copy = NULL;
    map->file = NULL;
    map->line = NULL;
    map->mlx = NULL;
    map->wnd = NULL;
}


int main(int ac, char **av)
{
    t_map map;

    if (ac == 2)
    {
    map_init(&map, av);
    map_checker(&map);
    map.mlx = mlx_init();
    map.wnd = mlx_new_window(map.mlx,map.y * IMG_PXL, map.x * IMG_PXL, "SO_LONG");
    file_to_img(&map);
    map_printer(&map);
    mlx_hook(map.wnd, 17, 0, ft_close, &map);
    mlx_key_hook(map.wnd, key_hook, &map);
    mlx_loop(map.mlx);
    return (0);
    }
    ft_printf("\033[1;31m🛑ERROR: Usage: ./so_long mapfile\n\033[0m");
	exit(EXIT_FAILURE);
}

