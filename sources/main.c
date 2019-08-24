/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 21:54:32 by ahiroko           #+#    #+#             */
/*   Updated: 2019/08/21 18:34:34 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	help_controls(void)
{
	ft_putstr("\033[1mMove\033[0m: arrows\n");
	ft_putstr("\033[1mZoom\033[0m: scroll\n");
	ft_putstr("\033[1mColor\033[0m: \"c\"\n");
	ft_putstr("\033[1mChange\033[0m: \"<\" / \">\"\n");
	ft_putstr("\033[1mIter\033[0m: \"+\" / \"-\" on numpad\n");
}

int			main(int argc, char **argv)
{
	t_env env;

	env.fract_id = check_input(argc, argv);
	init_env(&env);
	init_opencl(env.opcl);
	draw(&env);
	help_controls();
	key_hooks(&env);
	mlx_loop(env.mlx);
	return (0);
}
