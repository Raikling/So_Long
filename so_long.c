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
    void *img;
    void *img2;
    int a = 50;
    if (ac == 2)
    {
    map_init(&map, av);
    map.mlx = mlx_init();
    map.wnd = mlx_new_window(map.mlx,1000, 1000, "SO_LONG");
    img = mlx_xpm_file_to_image(map.mlx, "Ressources/GoldMine_Active.xpm", &a, &a);
    img2 = mlx_xpm_file_to_image(map.mlx, "Ressources/grass_template2.xpm", &a, &a);
    mlx_put_image_to_window(map.mlx,map.wnd, img2, 0, 0);
    mlx_put_image_to_window(map.mlx,map.wnd, img, 0, 0);
    mlx_loop(map.mlx);
    return (0);
    }
}

// #include <stdio.h> // For printf
// #include <stdlib.h> // For exit

// int main(int ac, char **av)
// {
//     t_map map;
//     void *img;
//     int img_width = 200;
//     int img_height = 200;

//     if (ac != 2)
//     {
//         printf("Error: Please provide one argument\n");
//         return (1);
//     }

//     map_init(&map, av);

//     map.mlx = mlx_init();
//     if (!map.mlx)
//     {
//         printf("Error: MLX initialization failed\n");
//         return (1);
//     }

//     map.wnd = mlx_new_window(map.mlx, 1000, 1000, "SO_LONG");
//     if (!map.wnd)
//     {
//         printf("Error: Window creation failed\n");
//         return (1);
//     }

//     img = mlx_xpm_file_to_image(map.mlx, "Ressources/space.xpm", &img_width, &img_height);
//     if (!img)
//     {
//         printf("Error: Failed to load 'Ressources/space.xpm' (check path or file format)\n");
//         printf("Working directory might not contain Ressources/space.xpm\n");
//         return (1);
//     }

//     printf("Image loaded successfully - Width: %d, Height: %d\n", img_width, img_height);

//     // Clear the window to ensure we have a clean slate
//     mlx_clear_window(map.mlx, map.wnd);

//     // Put the image on the window
//     mlx_put_image_to_window(map.mlx, map.wnd, img, 0, 0);

//     // Optional: Draw multiple instances to make it more visible
//     mlx_put_image_to_window(map.mlx, map.wnd, img, 200, 0);
//     mlx_put_image_to_window(map.mlx, map.wnd, img, 0, 200);

//     mlx_loop(map.mlx);

//     // Cleanup (though this won't be reached due to mlx_loop)
//     mlx_destroy_image(map.mlx, img);
//     mlx_destroy_window(map.mlx, map.wnd);
//     mlx_destroy_display(map.mlx);
//     free(map.mlx);

//     return (0);
// }
