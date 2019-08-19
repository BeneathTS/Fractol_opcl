/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 21:57:35 by ahiroko           #+#    #+#             */
/*   Updated: 2019/08/19 21:57:56 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	cl_err_exit(t_opcl *opcl, int err_code)
{
	clReleaseContext(opcl->context);
	clReleaseCommandQueue(opcl->queue);
	clReleaseProgram(opcl->program);
	clReleaseKernel(opcl->kernel);
	clReleaseMemObject(opcl->out);
	terminate(CL, err_code);
}

int		x_close(t_env *env)
{
	ft_bzero(env->data_addr, (WIDTH * env->bts_pr_pxl / 8) * HEIGHT);
	clReleaseContext(env->opcl->context);
	clReleaseCommandQueue(env->opcl->queue);
	clReleaseProgram(env->opcl->program);
	clReleaseKernel(env->opcl->kernel);
	clReleaseMemObject(env->opcl->out);
	mlx_destroy_image(env->mlx, env->img);
	terminate(STD, EXIT);
	return (0);
}

void	terminate(char flag, int err_code)
{
	if (flag == STD && err_code != EXIT)
		std_err(err_code);
	if (flag == CL)
		cl_errors(err_code);
	exit(0);
}
