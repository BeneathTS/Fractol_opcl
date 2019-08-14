#include "fractol.h"

int main(int argc, char **argv)
{
	t_env env;
	
	env.fract_id = check_input(argc, argv);
	init_env(&env);
	init_opencl(env.opcl);
	draw(&env);
	key_hooks(&env);
	mlx_loop(env.mlx);
	return (0);
}