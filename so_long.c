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
    map.mlx = mlx_init();
    map.wnd = mlx_new_window(map.mlx,1920, 1080, "SO_LONG");
    file_to_img(&map);
    map_array(&map);
    map_printer(&map);
    mlx_put_image_to_window(map.mlx,map.wnd, map.img.floor, 0, 0);
    mlx_loop(map.mlx);
    return (0);
    }
}

// int main(int ac, char **av)
// {
//     t_map map;
//     void *img;
//     void *img2;
//     int a = 50;
//     if (ac == 2)
//     {
//     map_init(&map, av);
//     map.mlx = mlx_init();
//     map.wnd = mlx_new_window(map.mlx,1000, 1000, "SO_LONG");
//     img = mlx_xpm_file_to_image(map.mlx, "Ressources/floor.xpm", &a, &a);
//     img2 = mlx_xpm_file_to_image(map.mlx, "Ressources/grass_template2.xpm", &a, &a);
//     mlx_put_image_to_window(map.mlx,map.wnd, img2, 0, 0);
//     mlx_put_image_to_window(map.mlx,map.wnd, img, 0, 0);
//     mlx_loop(map.mlx);
//     return (0);
//     }
// }