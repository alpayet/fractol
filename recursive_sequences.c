/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_sequences.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 23:25:45 by alpayet           #+#    #+#             */
/*   Updated: 2025/01/07 22:15:23 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	what_to_return(double x_n, double y_n, int n)
{
	if ((x_n - 1) * (x_n - 1) + y_n * y_n <= 0.001)
		return (n + 120);
	if ((x_n + 0.5) * (x_n + 0.5) + (y_n - 0.866025) * (y_n
			- 0.866025) <= 0.001)
		return (n + 240);
	return (n + 360);
}

int	newton(double x_0, double y_0, double c_coord1, double c_coord2)
{
	double	x_n;
	double	y_n;
	double	result[6];
	int		n;

	(void)c_coord1;
	(void)c_coord2;
	n = 0;
	x_n = x_0;
	y_n = y_0;
	while (((x_n - 1) * (x_n - 1) + y_n * y_n > 0.001) && ((x_n
				+ 0.5) * (x_n + 0.5) + (y_n - 0.866025) * (y_n
				- 0.866025) > 0.001) && ((x_n + 0.5) * (x_n + 0.5) + (y_n
				+ 0.866025) * (y_n + 0.866025) > 0.001))
	{
		complex_square(x_n, y_n, result);
		complex_product(result, x_n, y_n, result + 2);
		result[2] = 2 * result[2] + 1;
		result[3] = 2 * result[3];
		complex_quotient(result + 2, 3 * result[0], 3 * result[1], result + 4);
		x_n = result[4];
		y_n = result[5];
		n++;
	}
	return (what_to_return(x_n, y_n, n));
}

int	mandelbrot(double x_0, double y_0, double c_coord1, double c_coord2)
{
	double	x_n;
	double	y_n;
	double	result[4];
	int		n;

	(void)c_coord1;
	(void)c_coord2;
	n = 0;
	x_n = 0;
	y_n = 0;
	while (y_n * y_n + x_n * x_n < 1000)
	{
		complex_square(x_n, y_n, result);
		complex_sum(result, x_0, y_0, result + 2);
		x_n = result[2];
		y_n = result[3];
		if (n == 100 && (y_n * y_n + x_n * x_n) <= 4)
			return (0);
		n++;
	}
	return (n);
}

int	julia(double x_0, double y_0, double c_coord1, double c_coord2)
{
	double	x_n;
	double	y_n;
	double	result[4];
	int		n;

	n = 0;
	x_n = x_0;
	y_n = y_0;
	while ((x_n - x_0) * (x_n - x_0) + (y_n - y_0) * (y_n - y_0) < 1000)
	{
		complex_square(x_n, y_n, result);
		complex_sum(result, c_coord1, c_coord2, result + 2);
		x_n = result[2];
		y_n = result[3];
		if (n == 100 && (y_n * y_n + x_n * x_n) <= 4)
			return (0);
		n++;
	}
	return (n);
}
int	newton_gen(double x_0, double y_0, double c_coord1, double c_coord2)
{
	double	x_n;
	double	y_n;
	double	result[8];
	int		n;

	n = 0;
	x_n = x_0;
	y_n = y_0;
	while (((x_n - 1) * (x_n - 1) + y_n * y_n > 0.001) && ((x_n
				+ 0.5) * (x_n + 0.5) + (y_n - 0.866025) * (y_n
				- 0.866025) > 0.001) && ((x_n + 0.5) * (x_n + 0.5) + (y_n
				+ 0.866025) * (y_n + 0.866025) > 0.001))
	{
		complex_square(x_n, y_n, result);
		complex_product(result, x_n, y_n, result + 2);
		result[2] = result[2] - 1;
		complex_quotient(result + 2, -3 * result[0], -3 * result[1], result
			+ 4);
		complex_product(result + 4, c_coord1, c_coord2, result + 2);
		complex_sum(result + 2, x_n, y_n, result + 6);
		x_n = result[6];
		y_n = result[7];
		n++;
	}
	return (what_to_return(x_n, y_n, n));
}
