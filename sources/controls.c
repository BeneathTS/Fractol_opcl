/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 21:58:53 by ahiroko           #+#    #+#             */
/*   Updated: 2019/08/19 22:00:05 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_multi_mandel(int key, t_env *env)
{
	char temp;

	temp = env->fract_id;
	if (key == KB_KEY_ARR_RGHT && env->fract_id < BRN_SP_C)
	{
		++env->fract_id;
		env->cam->pause = OFF;
	}
	if (key == KB_KEY_ARR_LFT && MANDEL < env->fract_id)
		--env->fract_id;
	if (env->fract_id != temp || key == KB_KEY_R)
	{
		env->cam->x_off = 0;
		env->cam->y_off = 0;
		env->cam->zoom = 150;
		env->cam->zm_x = WIDTH / 2;
		env->cam->zm_y = HEIGHT / 2;
	}
	draw(env);
}

void	zoom(int button, int x, int y, t_env *env)
{
	double temp;

	temp = env->cam->zoom;
	if (button == MS_SCRL_UP || button == KB_NUM_PLUS)
		env->cam->zoom *= 1.1;
	if (button == MS_SCRL_DWN || button == KB_NUM_MIN)
		env->cam->zoom /= 1.1;
	if (env->cam->zoom < 5)
		env->cam->zoom = 5;
	env->cam->x_off -= -(x - env->cam->zm_x) / env->cam->zoom *
	(double)HEIGHT / WIDTH * 1.1;
	env->cam->y_off -= -(y - env->cam->zm_y) / env->cam->zoom *
	(double)HEIGHT / WIDTH * 1.1;
	env->cam->zm_x = x;
	env->cam->zm_y = y;
	draw(env);
}

void	move_cam(int key, t_env *env)
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

void	change_c_julia(t_env *env, int x, int y)
{
	if (x <= WIDTH && x >= 0 && y <= HEIGHT && y >= 0)
	{
		env->cam->ms_re = (x - WIDTH / 2) * 0.002;
		env->cam->ms_im = (y - HEIGHT / 2) * 0.002;
	}
	draw(env);
}
