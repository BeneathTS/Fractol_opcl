#include "fractol.h"

// void cl_errors(int err_code)
// {

// }

void std_err(int err_code)
{
	errno = err_code;
	if (err_code == INPUT_ERROR)
	{
		ft_putstr("\033[1;33mUsage\033[0m: ./fractol \"fractal flag\" \n\n");
		ft_putstr("Mandelbrot set: -m [+]\nJulia set: \t-j [+]\nBurning ship:\t-bs[-]\n");
	}
	else
		perror("\033[1;31mError!\033[0m");
}