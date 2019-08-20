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

char mandelbrot_check(char *arg)
{
	if (arg[1] == 'm' && !arg[2])
		return (MANDEL);
	else if (arg[1] == 'm' && arg[2] == 'm' && arg[3] == '3' && !arg[4])
		return (MULTI_MANDEL_3);
	else if (arg[1] == 'm' && arg[2] == 'm' && arg[3] == '4' && !arg[4])
		return (MULTI_MANDEL_4);
	else if (arg[1] == 'm' && arg[2] == 'm' && arg[3] == '5' && !arg[4])
		return (MULTI_MANDEL_5);
	else if (arg[1] == 'm' && arg[2] == 'm' && arg[3] == '6' && !arg[4])
		return (MULTI_MANDEL_6);
	return (0);
}

static char check_fract_id(char *arg)
{
	char temp;

	if (arg[0] != '-' || !arg[1])
		terminate(STD, INPUT_ERROR);
	if (arg[1] == 'j' && !arg[2])
		return (JUL);
	else if (arg[1] == 'b' && arg[2] == 's' && arg[3] == 'c' && !arg[4])
		return (BRN_SP_C);
	else if (arg[1] == 'b' && arg[2] == 's' && !arg[3])
		return (BRN_SP);
	else if (arg[1] == 't' && !arg[2])
		return (TRICORN);
	else if (arg[1] == 'c' && arg[2] == 'm' && !arg[3])
		return (CEL_MANDEL);
	else if (!(temp = mandelbrot_check(arg)))
		terminate(STD, INPUT_ERROR);
	return (temp);
}

char check_input(char *arg)
{
	return (check_fract_id(arg));
}