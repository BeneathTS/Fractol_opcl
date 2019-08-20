/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 21:54:32 by ahiroko           #+#    #+#             */
/*   Updated: 2019/08/19 21:54:41 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol(char *arg, t_env *env)
{
	env->fract_id = check_input(arg);
	init_env(env);
	init_opencl(env->opcl);
	draw(env);
	key_hooks(env);
	mlx_loop(env->mlx);
}

int		main(int argc, char **argv)
{
	t_env env;
	pid_t pid;

	if (argc < 2 || argc > 3)
		terminate(STD, INPUT_ERROR);
	if (argc == 3)
		switch (pid = fork())
		{
		case -1:
			terminate(STD, FORK_ERR);
		case 0:
			fractol(SEC_ARG, &env);
		}
	fractol(FIRST_ARG, &env);
	return (0);
}
