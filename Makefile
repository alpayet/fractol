.PHONY : all lib_libft lib_mlx clean fclean re
LIBFT_DIR = libft
MINILIBX_DIR = ../minilibx-linux
SRC = complex_operations.c hooks_management.c recursive_sequences.c zoom_and_color.c main.c
OBJ = $(SRC:.c=.o)
NAME = fractol
INC = fractol.h $(LIBFT_DIR)/libft.h $(MINILIBX_DIR)/mlx.h
CC = cc
CFLAGS = -Wall -Wextra -Werror -O3
LFLAGS = -L$(LIBFT_DIR) -lft -L$(MINILIBX_DIR) -lmlx -lXext -lX11 -lm
MAKE = @make --no-print-directory

all : lib_libft lib_mlx $(NAME)

$(NAME) : $(OBJ) $(LIBFT_DIR)/libft.a $(MINILIBX_DIR)/libmlx.a
	$(CC) -o $@ $(OBJ) $(LFLAGS)

%.o : %.c $(INC) Makefile
	$(CC) $(CFLAGS) -o $@ -c $<

lib_libft :
	$(MAKE) -C $(LIBFT_DIR)

lib_mlx :
	$(MAKE) -C $(MINILIBX_DIR)

clean :
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f ../minilibx-linux/*.o
	rm -f *.o

fclean : clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MINILIBX_DIR)
	rm -f $(NAME)

re : fclean all
