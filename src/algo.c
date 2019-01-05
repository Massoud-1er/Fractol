/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 16:29:39 by mmovahhe          #+#    #+#             */
/*   Updated: 2019/01/05 14:17:13 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void		algo_r_mandelbrot(int x, int y, t_args args)
{
	t_point	pt;
	double	tmp;
	int		i;

	pt.c_r = x / args.zoom + args.minx;
	pt.c_i = y / args.zoom + args.miny;
	pt.z_r = 0;
	pt.z_i = 0;
	i = 0;
	while (i < args.iter_max && pt.z_r * pt.z_r + pt.z_i * pt.z_i < 4)
	{
		tmp = pt.z_r;
		pt.z_r = pt.z_r * pt.z_r - pt.z_i * pt.z_i + pt.c_r;
		pt.z_i = -2 * pt.z_i * tmp + pt.c_i;
		i++;
	}
	if (i == args.iter_max)
		pixel_to_img(args.image, x, y, 0);
	else
		pixel_to_img(args.image, x, y, fcolor(i, 0, args.color));
}

void		algo_seahorse(int x, int y, t_args args)
{
	t_point	pt;
	double	tmp;
	int		i;

	pt.c_r = x / args.zoom + args.minx;
	pt.c_i = y / args.zoom + args.miny;
	pt.z_r = -0.3;
	pt.z_i = 0.989;
	i = 0;
	while (i < args.iter_max && pt.z_r * pt.z_r + pt.z_i * pt.z_i < 4)
	{
		tmp = pt.z_r;
		pt.z_r = pt.z_r * pt.z_r - pt.z_i * pt.z_i + pt.c_r;
		pt.z_i = 2.1 * pt.z_i * tmp + pt.c_i;
		i++;
	}
	if (i == args.iter_max)
		pixel_to_img(args.image, x, y, 0);
	else
		pixel_to_img(args.image, x, y, fcolor(i, 0, args.color));
}

void		algo_dendrite(int x, int y, t_args args)
{
	t_point	pt;
	int		i;
	double	tmp;

	pt.c_r = 0;
	pt.c_i = 1;
	pt.z_r = x / args.zoom + args.minx;
	pt.z_i = y / args.zoom + args.miny;
	i = 0;
	while (i < args.iter_max && pt.z_r * pt.z_r + pt.z_i * pt.z_i < 4)
	{
		tmp = pt.z_r;
		pt.z_r = pt.z_r * pt.z_r - pt.z_i * pt.z_i + pt.c_r;
		pt.z_i = 2 * pt.z_i * tmp + pt.c_i;
		i++;
	}
	if (i == args.iter_max)
		pixel_to_img(args.image, x, y, 0);
	else
		pixel_to_img(args.image, x, y, fcolor(i, 0, args.color));
}

void		algo_fatou_dust(int x, int y, t_args args)
{
	t_point	pt;
	int		i;
	double	tmp;

	pt.c_r = -0.76;
	pt.c_i = 0.12;
	pt.z_r = x / args.zoom + args.minx;
	pt.z_i = y / args.zoom + args.miny;
	i = 0;
	while (i < args.iter_max && pt.z_r * pt.z_r + pt.z_i * pt.z_i < 4)
	{
		tmp = pt.z_r;
		pt.z_r = pt.z_r * pt.z_r - pt.z_i * pt.z_i + pt.c_r;
		pt.z_i = -1.81 * pt.z_i * tmp + pt.c_i;
		i++;
	}
	if (i == args.iter_max)
		pixel_to_img(args.image, x, y, 0);
	else
		pixel_to_img(args.image, x, y, fcolor(i, 0, args.color));
}

void		algo(int x, int y, t_args *args)
{
	if (args->id == 1)
		algo_mandelbrot(x, y, *args);
	if (args->id == 2)
		algo_julia(x, y, *args);
	if (args->id == 3)
		algo_r_mandelbrot(x, y, *args);
	if (args->id == 4)
		algo_dendrite(x, y, *args);
	if (args->id == 5)
		algo_fatou_dust(x, y, *args);
	if (args->id == 6)
		algo_burning_ship(x, y, *args);
	if (args->id == 7)
		algo_douady_rabbit(x, y, *args);
	if (args->id == 8)
		algo_julia_stars(x, y, *args);
	if (args->id == 9)
		algo_seahorse(x, y, *args);
}
