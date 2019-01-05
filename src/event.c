/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 16:30:16 by mmovahhe          #+#    #+#             */
/*   Updated: 2019/01/05 14:17:03 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		iter(int key, t_args *args)
{
	if (key == PLUS)
		args->iter_max += 25;
	if (key == MINUS)
		args->iter_max -= 25;
	clear_img(args->image);
	ft_thread(args);
}

void		color(int key, t_args *args)
{
	if (key == 8)
		args->color++;
	if (args->color == 4)
		args->color = 1;
	clear_img(args->image);
	ft_thread(args);
}

int			key_hooks(int key, void *args)
{
	if (key == ESC)
	{
		free_all(args);
		exit(0);
	}
	if (key == AR_D || key == AR_L || key == AR_U || key == AR_R)
		move(key, args);
	if (key == PLUS || key == MINUS)
		iter(key, args);
	if (key == 8)
		color(key, args);
	return (0);
}

int			mouse_hook(int button, int x, int y, t_args *args)
{
	if (button == CLICK_U || button == CLICK_D)
		zoom(button, x, y, args);
	if (args->id == 2 && button == CLICK_L)
	{
		args->on_julia = args->on_julia == 0 ? 1 : 0;
		mlx_hook(args->win_ptr, 6, 1L << 6, move_julia, args);
	}
	return (0);
}
