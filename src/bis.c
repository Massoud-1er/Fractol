/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 16:29:56 by mmovahhe          #+#    #+#             */
/*   Updated: 2019/01/05 14:17:09 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		free_all(t_args *args)
{
	if (args->image->image)
		free(args->image->image);
	if (args->image)
		free(args->image);
}

int			zoom(int button, int x, int y, t_args *args)
{
	if (button == CLICK_U)
	{
		args->minx = (x / args->zoom + args->minx) - (x / (args->zoom * 1.2));
		args->miny = (y / args->zoom + args->miny) - (y / (args->zoom * 1.2));
		args->zoom *= 1.2;
		args->iter_max++;
	}
	if (button == CLICK_D && args->zoom > 1)
	{
		args->minx = (x / args->zoom + args->minx) - (x / (args->zoom / 1.2));
		args->miny = (y / args->zoom + args->miny) - (y / (args->zoom / 1.2));
		args->zoom /= 1.2;
		args->iter_max--;
	}
	clear_img(args->image);
	ft_thread(args);
	return (0);
}

void		move(int key, t_args *args)
{
	if (key == AR_L)
	{
		args->minx -= 100 / args->zoom;
		args->maxx -= 100 / args->zoom;
	}
	if (key == AR_R)
	{
		args->minx += 100 / args->zoom;
		args->maxx += 100 / args->zoom;
	}
	if (key == AR_U)
	{
		args->miny -= 100 / args->zoom;
		args->maxy -= 100 / args->zoom;
	}
	if (key == AR_D)
	{
		args->miny += 100 / args->zoom;
		args->maxy += 100 / args->zoom;
	}
	clear_img(args->image);
	ft_thread(args);
}

int			check_usage(int ac, char **av)
{
	if (ac != 2 && ac != 3)
	{
		put_usage();
		return (0);
	}
	if (ft_atoi(av[1]) < 1 || ft_atoi(av[1]) > 9 || ft_strlen(av[1]) != 1)
	{
		put_usage();
		return (0);
	}
	if (ac == 3)
	{
		if (ft_atoi(av[2]) < 1 || ft_atoi(av[2]) > 9 || ft_strlen(av[2]) != 1)
		{
			put_usage();
			return (0);
		}
	}
	return (1);
}
