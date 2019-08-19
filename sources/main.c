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

int	main(int argc, char **argv)
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
