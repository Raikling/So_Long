#include "so_long.h"

int ft_free_array(char **arr, int i)
{
    while (i > 0)
        free(arr[--i]);
    free(arr);
    return (0);
}

void ft_exit_free(t_map *map)
{
    if (map == NULL)
    {
        printf("Error: map is NULL\n");
        exit(EXIT_FAILURE);
    }
    if (map->array)
    {
        for (int i = 0; map->array[i]; i++)
        {
            free(map->array[i]);
            map->array[i] = NULL;
        }
        free(map->array);
        map->array = NULL;
    }
    if (map->copy)
    {
        for (int i = 0; map->copy[i]; i++)
        {
            free(map->copy[i]);
            map->copy[i] = NULL;
        }
        free(map->copy);
        map->copy = NULL;
    }
    if (map->file)
    {
        free(map->file);
        map->file = NULL;
    }
    if (map->line)
    {
        free(map->line);
        map->line = NULL;
    }
    printf("Exiting due to error\n");
    exit(EXIT_FAILURE);
}