#include "../../minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include <math.h>


long double *complex_sum(long double x1, long double y1, long double x2, long double y2)
{
	long double	*sum;
	sum = malloc(2 * sizeof(long double));
	if (sum == NULL)
		return (NULL);
	sum[0] = x1 + x2;
	sum[1] = y1 + y2;
	return(sum);
}
long double *complex_square(long double x, long double y)
{
	
	long double	*product;
	product = malloc(2 * sizeof(long double));
	if (product == NULL)
		return (NULL);
	product[0] = x * x - y * y;
	product[1] = 2 * x * y;
	return(product);
	
}
int nth_term(long double x_0, long double y_0, long double x_c, long double y_c, int n)
{
	long double x_n;
	long double y_n;
	long double *sum;
	long double *square;
	int	i;
	
	
	sum = NULL;
	square = NULL;
	i = 0;
	x_n = x_0;
	y_n = y_0;
	
	
	while (i < n)
	{
		square = complex_square(x_n, y_n);
		sum = complex_sum(square[0], square[1], x_c, y_c);
		x_n = sum[0];
		y_n = sum[1];
		if (x_n >= 2 || y_n >= 2)
			return (1);
		printf("x %Lf\n", x_n);
		printf("y %Lf\n", y_n);
		free(sum);
		free(square);	
		i++;
	}
	//printf("%f", sqrt( y_n*y_n + x_n*x_n));
	if (sqrtl( y_n*y_n + x_n*x_n) >= 2)
		return (1);
	return(0);
}
long double	*first_point(int x, int y, int dir)
{
	long double *coord;

	coord = malloc (2 * sizeof(long double));

	static long double	i = 10;
	
	if (dir == 1)
	{
		i = i/1.2;
		coord[0] = x - i;
		coord[1] = 1;
		return (coord);
	}
	i = i*2;
	coord[0] = x + i;
	coord[1] = 1;
	return (coord);


}
char	*f(char *a)
{
	a[0] = 'q';
	a[1] = '\0';
	return(a);
}
int main() 
{
	int	c;
	int	*d;

	char *aa;

	printf("%s", f(aa));
	printf("%f", fmod(370, 360));

	// d = malloc(1 * 4);
	// d[0] = 5;
	// void *a;


	// c = d[0];
	// free(d);
	// d = NULL;
	// printf("%d\n", nth_term(1, 0.2, -0.75, 0 , 10));


}

