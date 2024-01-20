/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:23:06 by hed-dyb           #+#    #+#             */
/*   Updated: 2024/01/20 15:25:33 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_sky_and_ground(t_prime *prime)
{
	int	half;
	int	i;
	int	j;

	i = -1;
	j = -1;
	half = SCREEN_HEI / 2;
	while (++j < half)
	{
		i = -1;
		while (++i < SCREEN_WID)
			ft_put_a_pixel(prime, i, j, prime->parse->c);
	}
	j--;
	while (++j < SCREEN_HEI)
	{
		i = -1;
		while (++i < SCREEN_WID)
			ft_put_a_pixel(prime, i, j, prime->parse->f);
	}
}

void	ft_show_3d_walls(t_prime *prime)
{
	double	teta;
	int		x_screen ;

	teta = FIELD_OF_VIEW / SCREEN_WID;
	prime->ray.r_angle = prime->player.angle - (FIELD_OF_VIEW / 2);
	prime->ray.r_angle = ft_normalizing(prime->ray.r_angle);
	x_screen = 0;
	while (x_screen < SCREEN_WID)
	{
		prime->ray.r_angle = ft_normalizing(prime->ray.r_angle);
		ft_ray_cast(prime);
		ft_length_on_screen(prime);
		ft_find_x_tile(prime);
		ft_show_the_colom(prime, x_screen);
		prime->ray.r_angle += teta;
		x_screen++;
	}
}

int	ft_raycast_and_render(t_prime *prime)
{
	int	parameter;

	ft_update_range(prime);
	ft_update_postion(prime);
	ft_update_angle(prime);
	mlx_destroy_image(prime->mlx_ptr, prime->img_ptr);
	prime->img_ptr = mlx_new_image(prime->mlx_ptr, SCREEN_WID, SCREEN_HEI);
	prime->ad_ptr = mlx_get_data_addr \
		(prime->img_ptr, &prime->bits, &prime->linesize, &parameter);
	ft_sky_and_ground(prime);
	ft_show_3d_walls(prime);
	ft_the_mini_map(prime);
	mlx_put_image_to_window \
		(prime->mlx_ptr, prime->win_ptr, prime->img_ptr, 0, 0);
	return (0);
}

void	ft_rendering(t_prime *prime)
{
	if (ft_init_mlx_data(prime) == false)
	{
		ft_clean_exit(prime);
	}
	mlx_hook(prime->win_ptr, KEY_PRESS, 0L, ft_press_events, prime);
	mlx_hook(prime->win_ptr, KEY_RELEASE, 0L, ft_release_events, prime);
	mlx_hook(prime->win_ptr, DESTROYNOTIFY, 0L, ft_close_botton, prime);
	mlx_loop_hook(prime->mlx_ptr, ft_raycast_and_render, prime);
	mlx_loop(prime->mlx_ptr);
}
