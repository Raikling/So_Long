SRC = so_long.c file_to_img.c map_printer.c map_array.c GNL/get_next_line.c GNL/get_next_line_utils.c free.c
OBJ = $(SRC:.c=.o)
NAME = so_long
CC = gcc
FLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -rf
PRINTF_DIR = ft_Printf
MLX_DIR = minilibx-linux
LIBFT_DIR = Libft

LIBS = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf 
INCLUDES = -I$(MLX_DIR) -I$(PRINTF_DIR) -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(PRINTF_DIR)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBS) $(INCLUDES)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ $(INCLUDES)

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re