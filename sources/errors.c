#include "fractol.h"

// void cl_errors(int err_code)
// {

// }
static void usage_err()
{
	ft_putstr("\033[1;33mUsage\033[0m: ./fractol \"fractal flag\" \n");
	ft_putstr("Mandelbrot set:\t\t-m\n");
	ft_putstr("Multibrot (x2):\t\t-mm3\n");
	ft_putstr("Multibrot (x3):\t\t-mm4\n");
	ft_putstr("Multibrot (x4):\t\t-mm5\n");
	ft_putstr("Multibrot (x5):\t\t-mm6\n");
	ft_putstr("Celtic Mandelbrot:\t-cm\n");
	ft_putstr("Tricorn:\t\t-t\n");
	ft_putstr("Julia set: \t\t-j\n");
	ft_putstr("Burning ship:\t\t-bs\nBurning ship(change):\t-bsc\n");
}

void std_err(int err_code)
{
	errno = err_code;
	if (err_code == INPUT_ERROR)
		usage_err();
	else
		perror("\033[1;31mError!\033[0m");
}