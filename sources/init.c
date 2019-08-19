/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 21:48:09 by ahiroko           #+#    #+#             */
/*   Updated: 2019/08/19 21:52:49 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_cam	*cam_init(void)
{
	t_cam *cam;

	if (!(cam = (t_cam*)malloc(sizeof(t_cam))))
		return (NULL);
	cam->iter = 40;
	cam->zoom = 150;
	cam->x_off = 0;
	cam->y_off = 0;
	cam->pause = OFF;
	cam->zm_x = WIDTH / 2;
	cam->zm_y = HEIGHT / 2;
	return (cam);
}

t_opcl	*opcl_init(void)
{
	t_opcl *opcl;

	if (!(opcl = (t_opcl *)malloc(sizeof(t_opcl))))
		return (NULL);
	return (opcl);
}

void	init_env(t_env *env)
{
	if (!(env->mlx = mlx_init()))
		terminate(STD, ENOMEM);
	if (!(env->cam = cam_init()))
		terminate(STD, ENOMEM);
	if (!(env->opcl = opcl_init()))
		terminate(STD, ENOMEM);
	if (!(env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "Fractol")))
		terminate(STD, ENOMEM);
	if (!(env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT)))
		terminate(STD, ENOMEM);
	env->data_addr = mlx_get_data_addr(env->img, &env->bts_pr_pxl,
	&env->sz_ln, &env->endian);
}
