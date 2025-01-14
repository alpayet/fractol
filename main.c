/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:45:36 by alpayet           #+#    #+#             */
/*   Updated: 2025/01/13 21:06:20 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	image_data_update(t_data *data, int (*f)(double, double, double,
			double))
{
	int		index;
	int		i;
	int		j;
	int		n;
	double	coord[2];

	i = 0;
	j = 0;
	while (j <= data->height)
	{
		i = 0;
		while (i <= data->width)
		{
			index = i * (data->bpp / 8) + j * data->size_line;
			pixel_to_coord(i, j, data, coord);
			n = f(coord[0], coord[1], data->coord_c[0], data->coord_c[1]);
			color_pixel(n, index, data);
			i++;
		}
		j++;
	}
}

void	initialise_data(t_data *data, char *str)
{
	data->width = 1000;
	data->height = 1000;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->width, data->height, "fract");
	data->img_axes = mlx_new_image(data->mlx, data->width, data->height);
	data->data_img_axes = mlx_get_data_addr(data->img_axes, &(data->bpp),
			&(data->size_line), &(data->endian));
	(data->square_params)[0] = -3;
	(data->square_params)[1] = 3;
	(data->square_params)[2] = 6;
	data->color_shift = 0;
	data->coord_c[0] = -0.75;
	data->coord_c[1] = 0;
	if (str[0] == 'J')
		data->f = julia;
	if (str[0] == 'M')
		data->f = mandelbrot;
	if (str[0] == 'N')
		data->f = newton_gen;
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		diff[3];

	if (argc == 1)
	{
		ft_putstr_fd("Julia\nMandelbrot\nNewton", 1);
		return (1);
	}
	diff[0] = ft_strncmp(argv[1], "Julia", ft_strlen(argv[1]));
	diff[1] = ft_strncmp(argv[1], "Mandelbrot", ft_strlen(argv[1]));
	diff[2] = ft_strncmp(argv[1], "Newton", ft_strlen(argv[1]));
	if (diff[0] != 0 && diff[1] != 0 && diff[2] != 0)
	{
		ft_putstr_fd("Julia\nMandelbrot\nNewton", 1);
		return (1);
	}
	data = malloc(sizeof(t_data));
	initialise_data(data, argv[1]);
	image_data_update(data, data->f);
	mlx_put_image_to_window(data->mlx, data->win, data->img_axes, 0, 0);
	mlx_mouse_hook(data->win, mouse_hook, data);
	mlx_key_hook(data->win, key_hook, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_loop(data->mlx);
} //rajouter un hook pour le nombre diterations, parsing pour mettre c en parametre
