/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:45:36 by alpayet           #+#    #+#             */
/*   Updated: 2024/12/16 00:40:22 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minilibx-linux/mlx.h"
#include <X11/X.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include <math.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void complex_sum(double x1, double y1, double x2, double y2, double *sum)
{
	sum[0] = x1 + x2;
	sum[1] = y1 + y2;
}
void complex_square(double x, double y, double *square)
{
	
	square[0] = x * x - y * y;
	square[1] = 2 * x * y;
}
int nth_term(double x_0, double y_0, double x_c, double y_c, int dist)
{
	double x_n;
	double y_n;
	double sum[2];
	double square[2];
	int	n;
	
	n = 0;
	x_n = x_0;
	y_n = y_0;
	
	
	while (sqrtl((y_n - y_0) * (y_n - y_0) + (x_n - x_0) * (x_n - x_0)) < dist)
	{
		
		complex_square(x_n, y_n, square);
		complex_sum(square[0], square[1], x_c, y_c, sum);
		x_n = sum[0];
		y_n = sum[1];
		if (n == 100 && sqrt(y_n*y_n + x_n*x_n) < 2)
			return (0);
		n++;
	}
	return(n);
}
void pixel_to_coord(int width, int height, int pixel_x, int pixel_y, double *square_params, double *coord_point)
{
	coord_point[0] = square_params[0] + square_params[2] / width * pixel_x;
	coord_point[1] = square_params[1] + square_params[2] / height * -pixel_y;
}
void square_around_xy(double coord_x, double coord_y, int button, double *square_params)
{
	if (button == 4)
		square_params[2] = square_params[2]/1.2;
	if (button == 5)
		square_params[2] = square_params[2]*1.2;
	square_params[0] = coord_x - square_params[2]/2;
	square_params[1] = coord_y + square_params[2]/2;
}
void hsv_to_rgb(int h, double s, double v, int *r, int *g, int *b)
{
    double c = v * s; 
    double x = c * (1 - fabs(fmod(h / 60.0, 2) - 1)); 
    double m = v - c;

    double r_prime, g_prime, b_prime;

    if (h >= 0 && h < 60)
        r_prime = c, g_prime = x, b_prime = 0;
    else if (h >= 60 && h < 120)
        r_prime = x, g_prime = c, b_prime = 0;
    else if (h >= 120 && h < 180)
        r_prime = 0, g_prime = c, b_prime = x;
    else if (h >= 180 && h < 240)
        r_prime = 0, g_prime = x, b_prime = c;
    else if (h >= 240 && h < 300)
        r_prime = x, g_prime = 0, b_prime = c;
    else
        r_prime = c, g_prime = 0, b_prime = x;

    *r = (int)((r_prime + m) * 255);
    *g = (int)((g_prime + m) * 255);
    *b = (int)((b_prime + m) * 255);
    
}

int	mouse_hook(int button,int x,int y,void *param)
{
	void **param_tab;
	char	*data_img_axes;
	int	width;
	int	height;
	int	bpp; 
	int	size_line;
	int	endian;
	int	index;
	double *square_params;
	
	
	param_tab = (void**)param;
	data_img_axes = (char*)param_tab[0];
	width = *(int*)param_tab[1];
	height = *(int*)param_tab[2];
	bpp = *(int*)param_tab[3];
	size_line = *(int*)param_tab[4];
	endian = *(int*)param_tab[5];
	square_params = (double*)param_tab[9];
	
	double coord_point[2];
	char color_pixel;
	static int color_shift = 0;
	int	i = 0;
	int	j = 0;
	int r, g, b;
	int N;
	double v;
	
	if (button == 4 || button == 5)
	{
		if (button == 4)
    			color_shift += 20;
		else
    			color_shift -= 20;
		pixel_to_coord(width, height, x, y, square_params, coord_point);
		square_around_xy((coord_point[0] + (square_params[0] + square_params[2]/2))/2, (coord_point[1] + (square_params[1] - square_params[2]/2))/2, button, square_params);
		printf("x%f , y%f, square%f\n", coord_point[0], coord_point[1], square_params[2]);	
		while (j <= height)
		{
			i = 0;
			while (i <= width)
			{
				index = i* (bpp/8) + j *size_line;
				pixel_to_coord(width, height, i, j, square_params, coord_point);
				N = nth_term(coord_point[0], coord_point[1], -0.75, 0, 100);
				if (N == 0)
					v = 0;
				else 
					v = 1;
				hsv_to_rgb((N *10 + color_shift) % 360, 0.55, v, &r, &g, &b);
				data_img_axes[index] = b;
				data_img_axes[index + 1] = g;
				data_img_axes[index + 2] = r;
				data_img_axes[index + 3] = 0;
				i++;
			}
			j++;
		}
		mlx_put_image_to_window(param_tab[6], param_tab[7], param_tab[8], 0, 0);
	}
	return (0);
}
int	expose_hook(void *param)
{
	void **param_tab = (void **)param;
	mlx_put_image_to_window(param_tab[6], param_tab[7], param_tab[8], 0, 0);
	return (0);
}
int	close_window(void *param)
{
	void **param_tab = (void **)param;
      mlx_destroy_image(param_tab[6], param_tab[8]);
	mlx_destroy_window(param_tab[6], param_tab[7]);
	free(param_tab);
	exit(0);
	return(0);
}
int	key_hook(int keycode,void *param)
{
	void **param_tab;
	char	*data_img_axes;
	int	width;
	int	height;
	int	bpp; 
	int	size_line;
	int	endian;
	int	index;
	double *square_params;
	
	
	param_tab = (void**)param;
	data_img_axes = (char*)param_tab[0];
	width = *(int*)param_tab[1];
	height = *(int*)param_tab[2];
	bpp = *(int*)param_tab[3];
	size_line = *(int*)param_tab[4];
	endian = *(int*)param_tab[5];
	square_params = (double*)param_tab[9];
	
	double coord_point[2];
	char color_pixel;
	static int color_shift = 0;
	int	i = 0;
	int	j = 0;
	int r, g, b;
	int N;
	double v;
	
	if (keycode == 65362)
	{
		square_around_xy(square_params[0] + square_params[2]/2, square_params[1] - square_params[2]/2 + square_params[2]/10 ,-1 , square_params);
		while (j <= height)
		{
			i = 0;
			while (i <= width)
			{
				index = i* (bpp/8) + j *size_line;
				pixel_to_coord(width, height, i, j, square_params, coord_point);
				N = nth_term(coord_point[0], coord_point[1], -0.75, 0, 100);
				if (N == 0)
					v = 0;
				else 
					v = 1;
				hsv_to_rgb((N *10 + color_shift) % 360, 0.55, v, &r, &g, &b);
				data_img_axes[index] = b;
				data_img_axes[index + 1] = g;
				data_img_axes[index + 2] = r;
				data_img_axes[index + 3] = 0;
				i++;
			}
			j++;
		}
		mlx_put_image_to_window(param_tab[6], param_tab[7], param_tab[8], 0, 0);
	}
	// if (keycode == 65364)
	// if (keycode == 65361)
	// if (keycode == 65363)
	if (keycode == 65307)
		close_window(param);
	return (0);
}
int	main(void)
{
	void	*mlx;
	void	*win;
	void	*img_axes;
	char	*data_img_axes;
	
	int	width;
	int	height;
	int	bpp; 
	int	size_line;
	int	endian;
	int	index;
	int 	hold_mouse_click = 0;
	int	i = 0;
	int	j = 0;
	double coord_point[2];
	void **param;


	width = 1000;
	height = 1000;
	mlx = mlx_init();
	win = mlx_new_window(mlx, width, height, "graphic representation of the plan");
	img_axes = mlx_new_image(mlx, width, height);
	data_img_axes = mlx_get_data_addr(img_axes, &bpp, &size_line, &endian);
	double square_params[3] = {-3, 3, 6};
	param = malloc(sizeof(void *) * 10);
	param[0] = data_img_axes;
	param[1] = &width;
	param[2] = &height;
	param[3] = &bpp;
	param[4] = &size_line;
	param[5] = &endian;
	param[6] = mlx;
	param[7] = win;
	param[8] = img_axes;
	param[9] = square_params;
	
	int r, g, b;
	int N;
	double v;
	
	while (j < height)
	{
		i = 0;
		while (i < width)
		{
			index = i* bpp /8 + j *size_line;
			pixel_to_coord(width, height, i, j, square_params, coord_point);
			N = nth_term(coord_point[0], coord_point[1], -0.75, 0, 100);
			if (N == 0)
				v = 0;
			else 
				v = 1;
			hsv_to_rgb(fmod(N * 10, 360), 0.55, v, &r, &g, &b);
			data_img_axes[index] = b;
			data_img_axes[index + 1] = g;
			data_img_axes[index + 2] = r;
			data_img_axes[index + 3] = 0;
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(mlx, win, img_axes, 0, 0);
	mlx_mouse_hook(win, mouse_hook, param);
	mlx_expose_hook(win, expose_hook, param);
	mlx_key_hook(win, key_hook, param);
	mlx_hook(win, 17, 0, close_window, param);
	mlx_loop(mlx);
 
}
// integrer une icone xpm -0.55, 0.8

