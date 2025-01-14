/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 22:08:35 by alpayet           #+#    #+#             */
/*   Updated: 2025/01/07 22:15:43 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <X11/X.h>
# include <math.h>
# include <stdlib.h>

typedef struct s_data
{
	void			*mlx;
	void			*win;
	void			*img_axes;
	char			*data_img_axes;
	int				width;
	int				height;
	int				bpp;
	int				size_line;
	int				endian;
	double			square_params[3];
	int				color_shift;
	double			coord_c[2];
	int				(*f)(double, double, double, double);
}					t_data;

void				complex_sum(double *z1_coord, double z2_coord1,
						double z2_coord2, double *sum);
void				complex_product(double *z1_coord, double z2_coord1,
						double z2_coord2, double *product);
void				complex_quotient(double *z1_coord, double z2_coord1,
						double z2_coord2, double *quotient);
void				complex_square(double x, double y, double *square);
int					newton_gen(double x_0, double y_0, double c_coord1,
						double c_coord2);
int					newton(double x_0, double y_0, double c_coord1,
						double c_coord2);
int					mandelbrot(double x_0, double y_0, double c_coord1,
						double c_coord2);
int					julia(double x_0, double y_0, double c_coord1,
						double c_coord2);
void				pixel_to_coord(int pixel_x, int pixel_y, t_data *data,
						double *coord);
void				square_around(double coord_x, double coord_y, int button,
						double *square_params);
void				color_pixel(int n, int index, t_data *data);
int					mouse_hook(int button, int x, int y, void *param);
int					close_window(void *param);
int					key_hook(int keycode, void *param);
void				image_data_update(t_data *data, int (*f)(double, double,
							double, double));
void				initialise_data(t_data *data, char *str);

#endif