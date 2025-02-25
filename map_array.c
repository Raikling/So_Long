#include "so_long.h"



void map_array(t_map *map)
{
    int fd;
    char *temp;
    map->x = 0;
    map->line = NULL;
    map->file = NULL;
    fd = open(map->filename, O_RDONLY);
    if (fd == -1)
        error_openfile();
    while (1)
    {
        map->line = get_next_line(fd);
        if (!map->line)
            break;
        if (!map->line[0])
        {
            free(map->line);
            map->line = NULL;
            continue;
        }
        temp = map->file;
        map->file = ft_strjoin(map->file, map->line);
        if (!map->file)
        {
            free(temp);
            free(map->line);
            map->line = NULL;
            close(fd);
            ft_exit_free(map);
        }
        free(temp);
        free(map->line);
        map->line = NULL;
        map->x++;
    }
    close(fd);
    map->array = ft_split(map->file, '\n');
    map->copy = ft_split(map->file, '\n');
    if (!map->array || !map->copy)
        ft_exit_free(map);
    free(map->file);
    map->file = NULL;
}
