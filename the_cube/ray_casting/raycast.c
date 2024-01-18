/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 11:50:29 by hed-dyb           #+#    #+#             */
/*   Updated: 2024/01/17 20:39:25 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_raycast_r1(t_prime *prime)
{
	if (prime->ray.r_angle == 0)
	{
		ft_special_case_r1(prime);
		prime->ray.hit = HIT_EAST;
		return ;
	}
	ft_update_line_r1(prime);
	ft_find_l_len_r1(prime);
	ft_update_col_r1(prime);
	ft_find_c_len_r1(prime);
	ft_update_hit_r1(prime);
	ft_final_update(prime);
	prime->ray.l_len = 0;
	prime->ray.c_len = 0;
}

void	ft_raycast_r2(t_prime *prime)
{
	if (prime->ray.r_angle == M_PI / 2)
	{
		ft_special_case_r2(prime);
		prime->ray.hit = HIT_SOUTH;
		return ;
	}
	ft_ft_update_line_r2(prime);
	ft_find_l_len_r2(prime);
	ft_update_col_r2(prime);
	ft_find_c_len_r2(prime);
	ft_update_hit_r2(prime);
	ft_final_update(prime);
	prime->ray.l_len = 0;
	prime->ray.c_len = 0;
}

void	ft_raycast_r3(t_prime *prime)
{
	if (prime->ray.r_angle == M_PI)
	{
		ft_special_case_r3(prime);
		prime->ray.hit = HIT_WEST;
		return ;
	}
	ft_update_line_r3(prime);
	ft_find_l_len_r3(prime);
	ft_update_col_r3(prime);
	ft_find_c_len_r3(prime);
	ft_update_hit_r3(prime);
	ft_final_update(prime);
	prime->ray.l_len = 0;
	prime->ray.c_len = 0;
}

void	ft_raycast_r4(t_prime *prime)
{
	if (prime->ray.r_angle == (3 * M_PI / 2))
	{
		ft_special_case_r4(prime);
		prime->ray.hit = HIT_NORTH;
		return ;
	}
	ft_update_line_r4(prime);
	ft_find_l_len_r4(prime);
	ft_update_col_r4(prime);
	ft_find_c_len_r4(prime);
	ft_update_hit_r4(prime);
	ft_final_update(prime);
	prime->ray.l_len = 0;
	prime->ray.c_len = 0;
}

void	ft_ray_cast(t_prime *prime)
{
	prime->ray.len = 0;
	if (prime->ray.r_angle >= 0 && prime->ray.r_angle < M_PI / 2)
		ft_raycast_r1(prime);
	else if (prime->ray.r_angle >= M_PI / 2 && prime->ray.r_angle < M_PI)
		ft_raycast_r2(prime);
	else if (prime->ray.r_angle >= M_PI && prime->ray.r_angle < (3 * M_PI / 2))
		ft_raycast_r3(prime);
	else
		ft_raycast_r4(prime);
}
