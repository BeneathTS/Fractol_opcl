#include "fractol.h"

int x_close(void *param)
{
	(void)param;
	terminate(STD, EXIT);
	return (0);
}

void terminate(char flag, int err_code)
{
	if (flag == STD && err_code != EXIT)
		std_err(err_code);
	if (flag == CL)
		printf("cl!\n");
	exit(0);
}