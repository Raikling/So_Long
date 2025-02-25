#include "so_long.h"

void error_filename(void)
{
  write(2, "\033[1;31m🛑ERROR: ", 16);
  write(2, " Filename should be a BER extention file\n\033[0m", 46);
  exit (EXIT_FAILURE);
}

void error_wall(t_map *map)
{
  write(2, "\033[1;31m🛑ERROR: ", 16);
  write(2, " Failed wall\n\033[0m", 18);
  ft_free_array(map->array, map->x);
  ft_free_array(map->copy, map->x);
  exit(EXIT_FAILURE);
}

void error_openfile(void)
{
  write(2, "\033[1;31m🛑ERROR: ", 16);
  write(2, " Failed open\n\033[0m", 18);
  exit(EXIT_FAILURE);
}

void error_size(t_map *map)
{
  write(2, "\033[1;31m🛑ERROR: ", 16);
  write(2, " Failed size\n\033[0m", 18);
  ft_free_array(map->array, map->x);
  ft_free_array(map->copy, map->x);
  exit(EXIT_FAILURE);
}

void error_map_elements(t_map *map)
{
  write(2, "\033[1;31m🛑ERROR: ", 16);
  write(2, " Failed elements\n\033[0m", 22);
  ft_free_array(map->array, map->x);
  ft_free_array(map->copy, map->x);
  exit(EXIT_FAILURE);
}