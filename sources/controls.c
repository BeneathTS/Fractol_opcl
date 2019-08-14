#include "fractol.h"

void zoom(int button, int x, int y, t_env *env)
{
	(void)x;
	(void)y;
	if (button == MS_SCRL_UP)
		env->cam->zoom += 0.03;
	if (button == MS_SCRL_DWN)
		env->cam->zoom -= 0.03;
	if (env->cam->zoom < 0.005)
		env->cam->zoom = 0.005;
	draw(env);
}

void move_cam(int key, t_env *env)
{
	if (key == KB_ARR_RGHT)
		env->cam->x_off -= 0.03 / env->cam->zoom;
	if (key == KB_ARR_LFT)
		env->cam->x_off += 0.03 / env->cam->zoom;
	if (key == KB_ARR_DWN)
		env->cam->y_off -= 0.03 / env->cam->zoom;
	if (key == KB_ARR_UP)
		env->cam->y_off += 0.03 / env->cam->zoom;
	draw(env);
}