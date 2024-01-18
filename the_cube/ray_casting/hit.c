/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 11:49:41 by hed-dyb           #+#    #+#             */
/*   Updated: 2024/01/17 20:47:38 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_update_hit_r1(t_prime *prime)
{
	if (prime->ray.l_len == 0)
	{
		prime->ray.hit = HIT_EAST;
		return ;
	}
	if (prime->ray.c_len == 0)
	{
		prime->ray.hit = HIT_SOUTH;
		return ;
	}
	if (prime->ray.c_len <= prime->ray.l_len)
		prime->ray.hit = HIT_EAST;
	else
		prime->ray.hit = HIT_SOUTH;
}

void	ft_update_hit_r2(t_prime *prime)
{
	if (prime->ray.l_len == 0)
	{
		prime->ray.hit = HIT_WEST;
		return ;
	}
	if (prime->ray.c_len == 0)
	{
		prime->ray.hit = HIT_SOUTH;
		return ;
	}
	if (prime->ray.l_len <= prime->ray.c_len)
		prime->ray.hit = HIT_SOUTH;
	else
		prime->ray.hit = HIT_WEST;
}

void	ft_update_hit_r3(t_prime *prime)
{
	if (prime->ray.l_len == 0)
	{
		prime->ray.hit = HIT_WEST;
		return ;
	}
	if (prime->ray.c_len == 0)
	{
		prime->ray.hit = HIT_NORTH;
		return ;
	}
	if (prime->ray.c_len <= prime->ray.l_len)
		prime->ray.hit = HIT_WEST;
	else
		prime->ray.hit = HIT_NORTH;
}

void	ft_update_hit_r4(t_prime *prime)
{
	if (prime->ray.c_len == 0)
	{
		prime->ray.hit = HIT_NORTH;
		return ;
	}
	if (prime->ray.l_len == 0)
	{
		prime->ray.hit = HIT_EAST;
		return ;
	}
	if (prime->ray.l_len < prime->ray.c_len)
		prime->ray.hit = HIT_NORTH;
	else
		prime->ray.hit = HIT_EAST;
}
