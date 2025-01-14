/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 23:37:25 by alpayet           #+#    #+#             */
/*   Updated: 2024/12/28 19:56:54 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	direction(t_data *data, int keycode, char x_or_y)
{
	if (keycode == 65362)
	{
		if (x_or_y == 'y')
			return (data->square_params[2] / 10);
		return (0);
	}
	if (keycode == 65364)
	{
		if (x_or_y == 'y')
			return (-data->square_params[2] / 10);
		return (0);
	}
	if (keycode == 65361)
	{
		if (x_or_y == 'x')
			return (-data->square_params[2] / 10);
		return (0);
	}
	if (x_or_y == 'x')
		return (data->square_params[2] / 10);
	return (0);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	t_data	*data;
	double	coord[2];

	data = (t_data *)param;
	if (button == 4 || button == 5)
	{
		if (button == 4)
			data->color_shift += 15;
		else
			data->color_shift -= 15;
		pixel_to_coord(x, y, data, coord);
		square_around((coord[0] + (data->square_params[0]
					+ data->square_params[2] / 2)) / 2, (coord[1]
				+ (data->square_params[1] - data->square_params[2] / 2)) / 2,
			button, data->square_params);
		image_data_update(data, data->f);
		mlx_put_image_to_window(data->mlx, data->win, data->img_axes, 0, 0);
	}
	return (0);
}

int	close_window(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	mlx_destroy_image(data->mlx, data->img_axes);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data);
	exit(0);
	return (0);
}

int	key_hook(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == 65362 || keycode == 65364 || keycode == 65361
		|| keycode == 65363)
	{
		square_around(data->square_params[0] + data->square_params[2] / 2
			+ direction(data, keycode, 'x'), data->square_params[1]
			- data->square_params[2] / 2 + direction(data, keycode, 'y'), -1,
			data->square_params);
	}
	if (keycode == 'w')
		data->coord_c[1] = data->coord_c[1] + 0.1;
	if (keycode == 's')
		data->coord_c[1] = data->coord_c[1] - 0.1;
	if (keycode == 'a')
		data->coord_c[0] = data->coord_c[0] - 0.1;
	if (keycode == 'd')
		data->coord_c[0] = data->coord_c[0] + 0.1;
	if (keycode == 65307)
		close_window(data);
	image_data_update(data, data->f);
	mlx_put_image_to_window(data->mlx, data->win, data->img_axes, 0, 0);
	return (0);
}
