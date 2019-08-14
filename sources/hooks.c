#include "fractol.h"

int key_controls(int key, t_env *env)
{
	if (key == KB_STD_ESC)
		x_close(env);
	if (key == KB_ARR_UP || key == KB_ARR_DWN ||
	key == KB_ARR_LFT || key == KB_ARR_RGHT)
		move_cam(key, env);
	return (0);
}

int mouse_controls_press(int button, int x, int y, t_env *env)
{
	if (button == MS_SCRL_UP || button == MS_SCRL_DWN)
		zoom(button, x, y, env);
	return (0);
}

void key_hooks(t_env *env)
{
	mlx_hook(env->win, 17, 0, x_close, env);
	mlx_hook(env->win, 2, 0, key_controls, env);
	mlx_hook(env->win, 4, 0, mouse_controls_press, env);
	//mlx_hook(frctl->win, 5, 0, mouse_controls_release, frctl);
	//mlx_hook(frctl->win, 6, 0, mouse_controls_move, frctl);
}