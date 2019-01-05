/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 16:30:34 by mmovahhe          #+#    #+#             */
/*   Updated: 2019/01/05 14:16:57 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void		print(t_thread *all_thread)
{
	int x;
	int y;

	x = 0;
	y = ((MAX_WIN_X * MAX_WIN_Y) / THREAD_NBR) * all_thread->thread_nb;
	while (y <= ((MAX_WIN_X) * MAX_WIN_Y) / THREAD_NBR *
			(all_thread->thread_nb + 1))
	{
		algo(x % (MAX_WIN_X), y / (MAX_WIN_X), all_thread->args);
		x++;
		y++;
	}
	pthread_exit(0);
}
