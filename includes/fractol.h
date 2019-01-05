/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 10:17:29 by jdescler          #+#    #+#             */
/*   Updated: 2019/01/05 14:17:19 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <../minilibx_macos/mlx.h>
# include "../libft/libft.h"
# include <stdio.h>
# include <math.h>
# include <pthread.h>

# define THREAD_NBR 9

/*
** Keys macro
*/
# define ESC 53
# define AR_L 123
# define AR_R 124
# define AR_U 126
# define AR_D 125
# define PLUS 69
# define MINUS 78

/*
**Mouse macro
*/
# define CLICK_L 1
# define CLICK_R 2
# define CLICK_U 4
# define CLICK_D 5

/*
** Macro Numbers
*/

# define MAX_WIN_X 1200
# define MAX_WIN_Y 900

/*
** Structures
*/
typedef	struct		s_point
{
	double c_r;
	double c_i;
	double z_r;
	double z_i;
}					t_point;

typedef	struct		s_coor
{
	double x1;
	double x2;
	double y1;
	double y2;
	double image_x;
	double image_y;
}					t_coor;

typedef	struct		s_img
{
	void	*ptr;
	char	*image;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
}					t_img;

typedef	struct		s_thread
{
	int				thread_nb;
	pthread_t		tid;
	pthread_attr_t	attr;
	void			*args;
}					t_thread;

typedef	struct		s_args
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			id;
	t_img		*image;
	double		zoom;
	int			color;
	int			pos_x;
	int			pos_y;
	double		iter_max;
	double		minx;
	double		miny;
	double		maxx;
	double		maxy;
	int			ac;
	double		julia_mv_x;
	double		julia_mv_y;
	int			on_julia;
	t_thread	all_thread[THREAD_NBR];
}					t_args;

/*
** Functions
*/
void				print(t_thread *all_thread);
void				algo(int x, int y, t_args *args);
int					key_hooks(int key, void *args);

/*
**	Error functions
*/
void				put_usage();
void				put_exit(void);
void				put_exit_free(t_args *args);
void				free_all(t_args *args);

/*
** Function colors
*/
size_t				fcolor(double i, size_t color, int id);
/*
**	images functions
*/

t_img				*create_image(t_args args);
void				pixel_to_img(t_img *img, int x, int y, int color);
void				clear_img(t_img *img);

/*
** Event functions
*/

int					zoom(int key, int x, int y, t_args *args);
int					mouse_hook(int buttom, int x, int y, t_args *args);
int					move_julia(int x, int y, t_args *args);
void				ft_thread(t_args *args);
void				move(int key, t_args *args);
int					check_usage(int ac, char **av);

/*
** Algo functions
*/

void				algo_julia(int x, int y, t_args args);
void				algo_douady_rabbit(int x, int y, t_args args);
void				algo_mandelbrot(int x, int y, t_args args);
void				algo_burning_ship(int x, int y, t_args args);
void				algo_julia_stars(int x, int y, t_args args);

#endif
