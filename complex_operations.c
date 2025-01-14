/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 23:21:30 by alpayet           #+#    #+#             */
/*   Updated: 2024/12/30 23:04:06 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

inline void	complex_sum(double *z1_coord, double z2_coord1, double z2_coord2,
		double *sum)
{
	sum[0] = z1_coord[0] + z2_coord1;
	sum[1] = z1_coord[1] + z2_coord2;
}

inline void	complex_product(double *z1_coord, double z2_coord1, double z2_coord2,
		double *product)
{
	product[0] = z1_coord[0] * z2_coord1 - z1_coord[1] * z2_coord2;
	product[1] = z1_coord[0] * z2_coord2 + z1_coord[1] * z2_coord1;
}

inline void	complex_quotient(double *z1_coord, double z2_coord1, double z2_coord2,
		double *quotient)
{
	double	denom;

	denom = 1.0 / (z2_coord1 * z2_coord1 + z2_coord2 * z2_coord2);
	quotient[0] = (z1_coord[0] * z2_coord1 + z1_coord[1] * z2_coord2) * denom;
	quotient[1] = (-z1_coord[0] * z2_coord2 + z1_coord[1] * z2_coord1) * denom;
}

inline void	complex_square(double x, double y, double *square)
{
	square[0] = x * x - y * y;
	square[1] = 2 * x * y;
}
