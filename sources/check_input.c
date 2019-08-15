#include "fractol.h"

static char check_fract_id(char **argv)
{
	if (argv[1][0] != '-')
		terminate(STD, INPUT_ERROR);
	if (argv[1][1] == 'm')
		return (MANDEL);
	else if (argv[1][1] == 'j')
		return (JUL);
	else if (argv[1][1] == 'b' && argv[1][2] == 's' && argv[1][3] == 'c')
		return (BRN_SP_C);
	else if (argv[1][1] == 'b' && argv[1][2] == 's')
		return (BRN_SP);
	else if (argv[1][1] == 't')
		return (TRICORN);
	else if (argv[1][1] == 'c' && argv[1][2] == 'm')
		return (CEL_MANDEL);
	terminate(STD, INPUT_ERROR);
	return (0);
}

char check_input(int argc, char **argv)
{
	if (argc != 2)
		terminate(STD, INPUT_ERROR);
	return (check_fract_id(argv));
}