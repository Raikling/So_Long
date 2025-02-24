 #include "so_long.h"




static void move_resume(t_map *map, int *x, int *y, int direction)
{
    // Update position based on direction
    if (direction == UP)
        *x -= 1;
    if (direction == DOWN)
        *x += 1;
    if (direction == LEFT)
        *y -= 1;
    if (direction == RIGHT)
        *y += 1;

    // Bounds checking to prevent out-of-bounds access
    if (*x < 0 || *x >= map->x || *y < 0 || *y >= map->y)
        return;

    // Handle exit: return if player reaches 'E' and all collectibles are gathered
    if (map->array[*x][*y] == 'E' && map->c == 0)
        return (ft_win(map));

    // Handle collectible: remove 'C' and decrement counter
    if (map->array[*x][*y] == 'C')
    {
        map->array[*x][*y] = '0';
        map->c--;
    }
}

void move_up(t_map *map)
{
    int x = map->player.x;
    int y = map->player.y;

    if (x > 0 && map->array[x - 1][y] != '1') // Check bounds and wall
    {
        move_resume(map, &x, &y, UP);
        // Prevent move if hitting exit with collectibles remaining or exit already triggered
        if (map->array[x][y] == 'E' && (map->c != 0 || map->exit == 1))
            return;

        map->moves++;
        // Clear current position
        mlx_put_image_to_window(map->mlx, map->wnd, map->img.floor, y * IMG_PXL, map->player.x * IMG_PXL);
        map->array[map->player.x][y] = '0';
        // Update player position
        map->player.x = x;
        // Draw new position
        mlx_put_image_to_window(map->mlx, map->wnd, map->img.floor, y * IMG_PXL, x * IMG_PXL);
        mlx_put_image_to_window(map->mlx, map->wnd, map->img.player, y * IMG_PXL, x * IMG_PXL);
        map->array[x][y] = 'P';
    }
}

void move_down(t_map *map)
{
    int x = map->player.x;
    int y = map->player.y;

    if (x < map->x && map->array[x + 1][y] != '1') // Check bounds and wall
    {
        move_resume(map, &x, &y, DOWN);
        if (map->array[x][y] == 'E' && (map->c != 0 || map->exit == 1))
            return;

        map->moves++;
        mlx_put_image_to_window(map->mlx, map->wnd, map->img.floor, y * IMG_PXL, map->player.x * IMG_PXL);
        map->array[map->player.x][y] = '0';
        map->player.x = x;
        mlx_put_image_to_window(map->mlx, map->wnd, map->img.floor, y * IMG_PXL, x * IMG_PXL);
        mlx_put_image_to_window(map->mlx, map->wnd, map->img.player, y * IMG_PXL, x * IMG_PXL);
        map->array[x][y] = 'P';
    }
}

void move_right(t_map *map)
{
    int x = map->player.x;
    int y = map->player.y;

    if (y < map->y && map->array[x][y + 1] != '1') // Check bounds and wall
    {
        move_resume(map, &x, &y, RIGHT);
        if (map->array[x][y] == 'E' && (map->c != 0 || map->exit == 1))
            return;

        map->moves++;
        mlx_put_image_to_window(map->mlx, map->wnd, map->img.floor, map->player.y * IMG_PXL, x * IMG_PXL);
        map->array[x][map->player.y] = '0';
        map->player.y = y;
        mlx_put_image_to_window(map->mlx, map->wnd, map->img.floor, y * IMG_PXL, x * IMG_PXL);
        mlx_put_image_to_window(map->mlx, map->wnd, map->img.player, y * IMG_PXL, x * IMG_PXL);
        map->array[x][y] = 'P';
    }
}

void move_left(t_map *map)
{
    int x = map->player.x;
    int y = map->player.y;

    if (y > 0 && map->array[x][y - 1] != '1') // Check bounds and wall
    {
        move_resume(map, &x, &y, LEFT);
        if (map->array[x][y] == 'E' && (map->c != 0 || map->exit == 1))
            return;

        map->moves++;
        mlx_put_image_to_window(map->mlx, map->wnd, map->img.floor, map->player.y * IMG_PXL, x * IMG_PXL);
        map->array[x][map->player.y] = '0';
        map->player.y = y;
        mlx_put_image_to_window(map->mlx, map->wnd, map->img.floor, y * IMG_PXL, x * IMG_PXL);
        mlx_put_image_to_window(map->mlx, map->wnd, map->img.player, y * IMG_PXL, x * IMG_PXL);
        map->array[x][y] = 'P';
    }
}