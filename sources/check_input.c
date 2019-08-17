#include "fractol.h"

char mandelbrot_check(char **argv)
{
	if (argv[1][1] == 'm' && !argv[1][2])
		return (MANDEL);
	else if (argv[1][1] == 'm' && argv[1][2] == 'm' && argv[1][3] == '3' && !argv[1][4])
		return (MULTI_MANDEL_3);
	else if (argv[1][1] == 'm' && argv[1][2] == 'm' && argv[1][3] == '4' && !argv[1][4])
		return (MULTI_MANDEL_4);
	else if (argv[1][1] == 'm' && argv[1][2] == 'm' && argv[1][3] == '5' && !argv[1][4])
		return (MULTI_MANDEL_5);
	else if (argv[1][1] == 'm' && argv[1][2] == 'm' && argv[1][3] == '6' && !argv[1][4])
		return (MULTI_MANDEL_6);
	return (0);
}

static char check_fract_id(char **argv)
{
	char temp;

	if (argv[1][0] != '-' || !argv[1][1])
		terminate(STD, INPUT_ERROR);
	if (argv[1][1] == 'j' && !argv[1][2])
		return (JUL);
	else if (argv[1][1] == 'b' && argv[1][2] == 's' && argv[1][3] == 'c' && !argv[1][4])
		return (BRN_SP_C);
	else if (argv[1][1] == 'b' && argv[1][2] == 's' && !argv[1][3])
		return (BRN_SP);
	else if (argv[1][1] == 't' && !argv[1][2])
		return (TRICORN);
	else if (argv[1][1] == 'c' && argv[1][2] == 'm' && !argv[1][3])
		return (CEL_MANDEL);
	else if (!(temp = mandelbrot_check(argv)))
		terminate(STD, INPUT_ERROR);
	return (temp);
}

char check_input(int argc, char **argv)
{
	if (argc != 2)
		terminate(STD, INPUT_ERROR);
	return (check_fract_id(argv));
}