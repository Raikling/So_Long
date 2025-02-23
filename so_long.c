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



// int main(int ac, char **av)
// {
//     t_map map;
//     if (ac != 2)
//     {
//         write(2, "\033[1;31m🛑ERROR: Usage: ./so_long <map.ber>\n\033[0m", 48);
//         return (1);
//     }
//     map_init(&map, av);
//     printf("Starting map checker...\n");
//     map_checker(&map);
//     printf("Initializing MLX...\n");
//     map.mlx = mlx_init();
//     if (!map.mlx)
//     {
//         write(2, "\033[1;31m🛑ERROR: mlx_init failed\n\033[0m", 35);
//         ft_exit_free(&map);
//     }
//     printf("Creating window...\n");
//     map.wnd = mlx_new_window(map.mlx, map.y * IMG_PXL, map.x * IMG_PXL, "SO_LONG");
//     if (!map.wnd)
//     {
//         write(2, "\033[1;31m🛑ERROR: Window creation failed\n\033[0m", 43);
//         ft_exit_free(&map);
//     }
//     printf("Loading images...\n");
//     file_to_img(&map);
//     printf("Drawing map...\n");
//     map_printer(&map);
//     printf("Entering loop...\n");
//     mlx_loop(map.mlx);
//     return (0);
// }
int main(int ac, char **av)
{
    t_map map;

    if (ac == 2)
    {
    map_init(&map, av);
    map_checker(&map);
    map_array(&map);
    map.mlx = mlx_init();
    map.wnd = mlx_new_window(map.mlx,map.y * IMG_PXL, map.x * IMG_PXL, "SO_LONG");
    file_to_img(&map);
    //map_printer(&map);
    mlx_put_image_to_window(map.mlx,map.wnd, map.img.player, 0, 0);
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