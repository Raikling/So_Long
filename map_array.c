#include "so_long.h"

// void map_array(t_map *map)
// {
//     int fd;
//     char *temp;

//     map->x = 0;
//     map->line = NULL;
//     map->file = NULL;

//     fd = open(map->filename, O_RDONLY);
//     // if (fd == -1)
//     //     //error_openfile();
//     while(1)
//     {
//         map->line = get_next_line(fd);
//         if(!map->line)
//             break;
//         if (!map->line[0]) // Handle empty line delete later if not working
//         {
//             free(map->line);
//             continue;
//         }
//         temp = map->file;
//         map->file = ft_strjoin(map->file, map->line);
//         if (!map->file)
//         {
//             free(temp);
//             free(map->line);
//             close(fd);
//             ft_exit_free(map);
//         }
//         free(temp);
//         free(map->line);
//         map->x++;
//     }
//     close(fd);
//     map->array = ft_split(map->file, '\n');
//     map->copy = ft_split(map->file, '\n');
//     if (!map->array || !map->copy)
//         ft_exit_free(map);
//     free(map->file);
// }





void map_array(t_map *map) {
    if (!map || !map->file) {
        return;
    }

    map->array = ft_split(map->file, '\n');
    if (!map->array) {
        return;
    }

    map->copy = ft_split(map->file, '\n');
    if (!map->copy) {
        // Free map->array if map->copy allocation fails
        int i = 0;
        while (map->array[i] != NULL) {
            free(map->array[i]);
            i++;
        }
        free(map->array);
        return;
    }

    // Example of handling memory allocation and deallocation
    int i = 0;
    while (map->array[i] != NULL) {
        // Process each line in the array
        i++;
    }

    // Free the array after use
    i = 0;
    while (map->array[i] != NULL) {
        free(map->array[i]);
        i++;
    }
    free(map->array);

    i = 0;
    while (map->copy[i] != NULL) {
        free(map->copy[i]);
        i++;
    }
    free(map->copy);
}