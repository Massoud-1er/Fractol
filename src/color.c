/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 16:30:04 by mmovahhe          #+#    #+#             */
/*   Updated: 2019/01/05 14:17:07 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

size_t		redder(double i, size_t color)
{
	size_t r;
	size_t g;
	size_t b;

	r = (color & 0xff);
	g = (color & 0xff00) >> 8;
	b = (color & 0xff0000) >> 16;
	b = i * 4;
	g = i * 6;
	r = i * 7 + 25;
	return ((b << 16) + (g << 8) + r);
}

size_t		bluer(double i, size_t color)
{
	size_t r;
	size_t g;
	size_t b;

	r = (color & 0xff);
	g = (color & 0xff00) >> 8;
	b = (color & 0xff0000) >> 16;
	b = i * 7 + 25;
	g = i * 4;
	r = i * 6;
	return ((b << 16) + (g << 8) + r);
}

size_t		greener(double i, size_t color)
{
	size_t r;
	size_t g;
	size_t b;

	r = (color & 0xff);
	g = (color & 0xff00) >> 8;
	b = (color & 0xff0000) >> 16;
	b = i * 6;
	g = i * 7 + 25;
	r = i * 4;
	return ((b << 16) + (g << 8) + r);
}

size_t		fcolor(double i, size_t color, int id)
{
	if (id == 1)
		return (redder(i, color));
	if (id == 2)
		return (bluer(i, color));
	if (id == 3)
		return (greener(i, color));
	return (0);
}
