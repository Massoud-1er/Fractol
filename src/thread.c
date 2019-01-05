/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 16:30:40 by mmovahhe          #+#    #+#             */
/*   Updated: 2019/01/05 14:16:54 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		*inter_print(void *args)
{
	print(args);
	pthread_exit(0);
}

void		ft_img_to_win(t_args *args)
{
	mlx_put_image_to_window(args->mlx_ptr, args->win_ptr,
			args->image->ptr, 0, 0);
}

void		ft_thread(t_args *args)
{
	int			i;

	i = 0;
	while (i < THREAD_NBR)
	{
		args->all_thread[i].thread_nb = i;
		args->all_thread[i].args = args;
		pthread_attr_init(&args->all_thread[i].attr);
		pthread_create(&args->all_thread[i].tid, &args->all_thread[i].attr,
				inter_print, &args->all_thread[i]);
		i++;
	}
	i = 0;
	while (i < THREAD_NBR)
	{
		pthread_join(args->all_thread[i].tid, NULL);
		i++;
	}
	ft_img_to_win(args);
}
