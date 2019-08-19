/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 21:55:02 by ahiroko           #+#    #+#             */
/*   Updated: 2019/08/19 21:55:58 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_controls(int key, t_env *env)
{
	if (key == KB_STD_ESC)
		x_close(env);
	if (key == KB_ARR_UP || key == KB_ARR_DWN ||
	key == KB_ARR_LFT || key == KB_ARR_RGHT)
		move_cam(key, env);
	if (key == KB_STD_SPACE)
		env->cam->pause = (env->cam->pause == ON ? OFF : ON);
	if (key == KB_KEY_ARR_LFT || key == KB_KEY_ARR_RGHT || key == KB_KEY_R)
		change_multi_mandel(key, env);
	return (0);
}

int		mouse_controls_press(int button, int x, int y, t_env *env)
{
	if (button == MS_SCRL_UP || button == MS_SCRL_DWN)
		zoom(button, x, y, env);
	return (0);
}

int		mouse_controls_move(int x, int y, t_env *env)
{
	if (env->cam->pause == OFF)
		change_c_julia(env, x, y);
	return (0);
}

void	key_hooks(t_env *env)
{
	mlx_hook(env->win, 17, 0, x_close, env);
	mlx_hook(env->win, 2, 0, key_controls, env);
	mlx_hook(env->win, 4, 0, mouse_controls_press, env);
	mlx_hook(env->win, 6, 0, mouse_controls_move, env);
}
