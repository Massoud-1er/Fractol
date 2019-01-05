/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 12:23:03 by mmovahhe          #+#    #+#             */
/*   Updated: 2019/01/05 14:17:11 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void		algo_julia(int x, int y, t_args args)
{
	t_point	pt;
	int		i;
	double	tmp;

	pt.c_r = 0.285;
	pt.c_i = 0.01 + args.julia_mv_x;
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

void		algo_julia_stars(int x, int y, t_args args)
{
	t_point	pt;
	int		i;
	double	tmp;

	pt.c_r = 0.3;
	pt.c_i = 0.7;
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

void		algo_douady_rabbit(int x, int y, t_args args)
{
	t_point	pt;
	int		i;
	double	tmp;

	pt.c_r = -0.123;
	pt.c_i = 0.745;
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

void		algo_mandelbrot(int x, int y, t_args args)
{
	t_point	pt;
	int		i;
	double	tmp;

	pt.c_r = x / args.zoom + args.minx;
	pt.c_i = y / args.zoom + args.miny;
	pt.z_r = 0;
	pt.z_i = 0;
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

void		algo_burning_ship(int x, int y, t_args args)
{
	t_point	pt;
	int		i;
	double	tmp;

	pt.c_r = x / args.zoom + args.minx;
	pt.c_i = y / args.zoom + args.miny;
	pt.z_r = 0;
	pt.z_i = 0;
	i = 0;
	while (i < args.iter_max && pt.z_r * pt.z_r + pt.z_i * pt.z_i < 4)
	{
		tmp = pt.z_r;
		pt.z_r = pt.z_r * pt.z_r - pt.z_i * pt.z_i + pt.c_r;
		pt.z_i = 2 * fabs(pt.z_i * tmp) + pt.c_i;
		i++;
	}
	if (i == args.iter_max)
		pixel_to_img(args.image, x, y, 0);
	else
		pixel_to_img(args.image, x, y, fcolor(i, 0, args.color));
}
