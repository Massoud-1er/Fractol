/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 16:30:26 by mmovahhe          #+#    #+#             */
/*   Updated: 2019/01/05 14:16:59 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_all(t_args *args, int argc)
{
	args->zoom = 300;
	args->pos_x = 0;
	args->pos_y = 0;
	args->iter_max = 80;
	args->color = 1;
	args->julia_mv_x = 0;
	args->julia_mv_y = 0;
	args->on_julia = 0;
	args->ac = argc;
}

void		init_args(t_args *args, int argc)
{
	init_all(args, argc);
	if (args->id == 1 || args->id == 3)
	{
		args->minx = -2.1;
		args->miny = -1.2;
		args->maxx = 0.6;
		args->maxy = 1.2;
	}
	if (args->id == 2 || args->id == 7)
	{
		args->minx = -1;
		args->maxx = 1;
		args->miny = -1.2;
		args->maxy = 1.2;
	}
	if (args->id == 6)
	{
		args->minx = -2.2;
		args->miny = -2.5;
	}
}

int			move_julia(int x, int y, t_args *args)
{
	(void)y;
	if (args->on_julia == 1)
	{
		args->julia_mv_x += x;
		args->julia_mv_x /= 1800;
		clear_img(args->image);
		ft_thread(args);
	}
	return (0);
}

void		init_env(t_args *args, t_args *args2)
{
	args->mlx_ptr = mlx_init();
	args2->mlx_ptr = mlx_init();
	if (!(args->win_ptr = mlx_new_window(args->mlx_ptr,
					MAX_WIN_X / (-1 + args->ac), MAX_WIN_Y, "mlx 42")))
		put_exit_free(args);
	if (args->ac > 2)
	{
		if (!(args2->win_ptr = mlx_new_window(args->mlx_ptr,
						MAX_WIN_X / (-1 + args->ac), MAX_WIN_Y, "mlx 42")))
			put_exit_free(args2);
		if (!(args2->image = create_image(*args2)))
			put_exit_free(args2);
	}
	if (!(args->image = create_image(*args)))
		put_exit_free(args);
}

int			main(int ac, char **av)
{
	t_args	args;
	t_args	args2;

	if (!check_usage(ac, av))
		return (0);
	init_args(&args, ac);
	init_args(&args2, ac);
	args.id = ft_atoi(av[1]);
	args2.id = av[2] ? ft_atoi(av[2]) : 0;
	init_env(&args, &args2);
	ft_thread(&args);
	if (ac == 3)
	{
		ft_thread(&args2);
		mlx_key_hook(args2.win_ptr, key_hooks, &args2);
		mlx_mouse_hook(args2.win_ptr, mouse_hook, &args2);
	}
	mlx_key_hook(args.win_ptr, key_hooks, &args);
	mlx_mouse_hook(args.win_ptr, mouse_hook, &args);
	mlx_loop(args.mlx_ptr);
	mlx_loop(args2.mlx_ptr);
	return (0);
}
