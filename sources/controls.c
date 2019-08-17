#include "fractol.h"

void change_multi_mandel(int key, t_env *env)
{
	char temp;
	temp = env->fract_id;
	if (key == KB_KEY_ARR_RGHT && env->fract_id < MULTI_MANDEL_6)
		++env->fract_id;
	if (key == KB_KEY_ARR_LFT && MANDEL < env->fract_id)
		--env->fract_id;
	if (env->fract_id != temp || key == KB_KEY_R)
	{
		env->cam->x_off = 0;
		env->cam->y_off = 0;
		env->cam->zoom = 150;
	}
	draw(env);
}

void zoom(int button, int x, int y, t_env *env)
{
	(void)x;
	(void)y;
	
	if (button == MS_SCRL_UP || button == KB_NUM_PLUS)
		env->cam->zoom *= 1.1;
	if (button == MS_SCRL_DWN || button == KB_NUM_MIN)
		env->cam->zoom /= 1.1;
	if (env->cam->zoom < 5)
		env->cam->zoom = 5;
	draw(env);
}

void move_cam(int key, t_env *env)
{
	if (key == KB_ARR_RGHT)
		env->cam->x_off -= 0.03 * WIDTH / env->cam->zoom;
	if (key == KB_ARR_LFT)
		env->cam->x_off += 0.03 * HEIGHT / env->cam->zoom;
	if (key == KB_ARR_DWN)
		env->cam->y_off -= 0.03 * WIDTH / env->cam->zoom;
	if (key == KB_ARR_UP)
		env->cam->y_off += 0.03 * HEIGHT / env->cam->zoom;
	draw(env);
}

void change_c_julia(t_env *env, int x, int y)
{
	if (x <= WIDTH && x >= 0 && y <= HEIGHT && y >= 0)
	{
		env->cam->ms_re = (x - WIDTH / 2) * 0.002;
		env->cam->ms_im = (y - HEIGHT / 2) * 0.002;
	}
	draw(env);
}