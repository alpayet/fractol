/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_and_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 23:34:38 by alpayet           #+#    #+#             */
/*   Updated: 2024/12/29 21:41:32 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

inline void	pixel_to_coord(int pixel_x, int pixel_y, t_data *data, double *coord)
{
	coord[0] = data->square_params[0] + data->square_params[2] / data->width
		* pixel_x;
	coord[1] = data->square_params[1] - data->square_params[2] / data->height
		* pixel_y;
}

void	square_around(double coord_x, double coord_y, int button,
		double *square_params)
{
	if (button == 4)
		square_params[2] = square_params[2] / 1.2;
	if (button == 5)
		square_params[2] = square_params[2] * 1.2;
	square_params[0] = coord_x - square_params[2] / 2;
	square_params[1] = coord_y + square_params[2] / 2;
}

static void	rgbp_to_rgb(float r_prime, float g_prime, float b_prime, char *rgb)
{
	rgb[0] = (char)(r_prime * 255);
	rgb[1] = (char)(g_prime * 255);
	rgb[2] = (char)(b_prime * 255);
}

static void	hsv_to_rgb(int h, int v, char *rgb)
{
	float	x;

	x = v * (1 - fabsf(fmodf(h / 60.0, 2) - 1));
	if (h >= 0 && h < 60)
		rgbp_to_rgb(v, x, 0, rgb);
	else if (h >= 60 && h < 120)
		rgbp_to_rgb(x, v, 0, rgb);
	else if (h >= 120 && h < 180)
		rgbp_to_rgb(0, v, x, rgb);
	else if (h >= 180 && h < 240)
		rgbp_to_rgb(0, x, v, rgb);
	else if (h >= 240 && h < 300)
		rgbp_to_rgb(x, 0, v, rgb);
	else
		rgbp_to_rgb(v, 0, x, rgb);
}

void	color_pixel(int n, int index, t_data *data)
{
	char	rgb[3];

	if (n == 0)
		hsv_to_rgb((n * 10 + data->color_shift) % 360, 0, rgb);
	else
		hsv_to_rgb((n * 10 + data->color_shift) % 360, 1, rgb);
	data->data_img_axes[index] = rgb[2];
	data->data_img_axes[index + 1] = rgb[1];
	data->data_img_axes[index + 2] = rgb[0];
	data->data_img_axes[index + 3] = 0;
}
