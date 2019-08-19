/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 21:56:16 by ahiroko           #+#    #+#             */
/*   Updated: 2019/08/19 21:57:13 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char		mandelbrot_check(char **av)
{
	if (av[1][1] == 'm' && !av[1][2])
		return (MANDEL);
	else if (av[1][1] == 'm' && av[1][2] == 'm' && av[1][3] == '3' && !av[1][4])
		return (MULTI_MANDEL_3);
	else if (av[1][1] == 'm' && av[1][2] == 'm' && av[1][3] == '4' && !av[1][4])
		return (MULTI_MANDEL_4);
	else if (av[1][1] == 'm' && av[1][2] == 'm' && av[1][3] == '5' && !av[1][4])
		return (MULTI_MANDEL_5);
	else if (av[1][1] == 'm' && av[1][2] == 'm' && av[1][3] == '6' && !av[1][4])
		return (MULTI_MANDEL_6);
	else if (av[1][1] == 't' && !av[1][2])
		return (TRICORN);
	else if (av[1][1] == 'c' && av[1][2] == 'm' && !av[1][3])
		return (CEL_MANDEL);
	else if (av[1][1] == 'c' && av[1][2] == 'm' && av[1][3] == 'c' && !av[1][4])
		return (CEL_MANDEL_C);
	return (0);
}

static char	check_fract_id(char **av)
{
	char temp;

	if (av[1][0] != '-' || !av[1][1])
		terminate(STD, INPUT_ERROR);
	if (av[1][1] == 'j' && !av[1][2])
		return (JUL);
	else if (av[1][1] == 'b' && av[1][2] == 's' && av[1][3] == 'c' && !av[1][4])
		return (BRN_SP_C);
	else if (av[1][1] == 'b' && av[1][2] == 's' && !av[1][3])
		return (BRN_SP);
	else if (!(temp = mandelbrot_check(av)))
		terminate(STD, INPUT_ERROR);
	return (temp);
}

char		check_input(int argc, char **argv)
{
	if (argc != 2)
		terminate(STD, INPUT_ERROR);
	return (check_fract_id(argv));
}
