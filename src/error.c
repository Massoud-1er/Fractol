/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 16:30:12 by mmovahhe          #+#    #+#             */
/*   Updated: 2019/01/05 14:17:05 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			error(int i)
{
	static int tmp = 0;

	if (i == 0)
		return (1);
	if (tmp == 0)
		tmp = i;
	if (tmp == i)
		return (0);
	put_exit();
	return (1);
}

void		put_exit(void)
{
	ft_putendl("oups, il y a un pb");
	ft_putendl("usage: ./fractal [1-9]");
	exit(0);
}

void		put_exit_free(t_args *args)
{
	free_all(args);
	put_exit();
}

void		put_usage(void)
{
	ft_putendl("usage: ./fractal [1-8]");
	ft_putendl("1 = Mandelbrot's fractal");
	ft_putendl("2 = Julia's fractal");
	ft_putendl("3 = Reversed Mandelbrot's fractal");
	ft_putendl("4 = Dendrite");
	ft_putendl("5 = Fatou dust");
	ft_putendl("6 = Burning Ship fractal");
	ft_putendl("7 = Douady rabbit");
	ft_putendl("8 = Julia's stars");
	ft_putendl("9 = Seahorse fractal");
}
