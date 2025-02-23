#ifndef SO_LONG_H
#define SO_LONG_H



#include <unistd.h>
#include <stdio.h>
#include <X11/X.h>
#include "minilibx-linux/mlx.h"
#include "GNL/get_next_line.h"
#include "ft_Printf/ft_printf.h"
#include <fcntl.h>
#include <math.h>


#define IMG_PXL 50
#define UP 119
#define DOWN 115
#define LEFT 97
#define RIGHT 100
#define ESC 65307

typedef struct s_player
{
    int x;
    int y;
}   t_player;

typedef struct s_img
{
    void *floor;
    void *player;
    void *collectible;
    void *wall;
    void *exit;
    void *enemy;
}   t_img;

typedef struct s_map
{
    int fd;
    char *line;
    char *file;
    char **array;
    char **copy;
    char *filename;
    int x;
    int y;
    int e;
    int c;
    int e_check;
    int c_check;
    int p;
    int exit;
    int moves;
    void *mlx;
    void *wnd;
    t_img img;
    t_player player;
}   t_map;


void file_to_image(t_map *map);
void map_printer(t_map *map);

#endif