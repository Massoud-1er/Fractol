/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 16:30:22 by mmovahhe          #+#    #+#             */
/*   Updated: 2019/01/05 14:17:01 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		pixel_to_img(t_img *img, int x, int y, int color)
{
	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	*(int *)(img->image + ((x + y * img->width) * img->bpp / 8)) = color;
}

void		clear_img(t_img *img)
{
	ft_bzero(img->image, img->width * img->height * img->bpp / 8);
}

t_img		*create_image(t_args args)
{
	t_img *img;

	if (!(img = ft_memalloc(sizeof(t_img))))
		put_exit_free(&args);
	if (!(img->ptr = mlx_new_image(args.mlx_ptr, MAX_WIN_X, MAX_WIN_Y)))
	{
		free(img);
		put_exit_free(&args);
	}
	if (!(img->image = mlx_get_data_addr(img->ptr,
					&(img->bpp), &(img->size_line), &(img->endian))))
	{
		free(img);
		put_exit_free(&args);
	}
	img->width = MAX_WIN_X;
	img->height = MAX_WIN_Y;
	return (img);
}
