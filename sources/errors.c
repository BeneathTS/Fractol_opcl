#include "fractol.h"

void cl_errors(int err_code)
{
	ft_putstr("\033[1;31mError!\033[0m");
	if (err_code == ERR_INIT_DEVICE)
		ft_putstr("Can't get CL-Device ID!\n");
	else if (err_code == ERR_INIT_COMMAND_QUEUE)
		ft_putstr("Can't init Command queue!\n");
	else if (err_code == ERR_INIT_CONTEXT)
		ft_putstr("Can't init context!\n");
	else if (err_code == ERR_INIT_PROGRAM)
		ft_putstr("Can't init program!\n");
	else if (err_code == ERR_BUILD_PROGRAM)
		ft_putstr("Can't build binary code!\n");
	else if (err_code == ERR_INIT_KERNEL)
		ft_putstr("Can't init kernel!\n");
	else if (err_code == ERR_INIT_GLOBAL_BUF)
		ft_putstr("Can't init CL global variable!\n");
	else if (err_code == ERR_SET_KERNEL_ARG)
		ft_putstr("Can't set arguments to kernel!\n");
	else if(err_code == ERR_GET_LOCAL_SIZE)
		ft_putstr("Can't get Work Group local size!\n");
	else if(err_code == ERR_NDRANGE)
		ft_putstr("Can't launch kernel!\n");
}

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