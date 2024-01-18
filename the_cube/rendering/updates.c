/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:29:07 by hed-dyb           #+#    #+#             */
/*   Updated: 2024/01/18 16:14:11 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

double	ft_normalizing(double angle)
{
	if (angle < 0)
	{
		angle += (2 * M_PI);
		return (angle);
	}
	if (angle >= (2 * M_PI))
	{
		angle -= (2 * M_PI);
		return (angle);
	}
	return (angle);
}

void	ft_update_range(t_prime *prime)
{
	if (prime->player.angle >= 0 && prime->player.angle < (M_PI / 2))
		prime->angle_range = 1;
	if (prime->player.angle >= (M_PI / 2) && prime->player.angle < M_PI)
		prime->angle_range = 2;
	if (prime->player.angle >= M_PI && prime->player.angle < (3 * M_PI / 2))
		prime->angle_range = 3;
	if (prime->player.angle >= (3 * M_PI / 2) \
		&& prime->player.angle < (2 * M_PI))
		prime->angle_range = 4;
}

void	ft_update_angle(t_prime *prime)
{
	if (prime->rotate_status == 1)
		prime->player.angle += ROTATE_ANGLE;
	if (prime->rotate_status == -1)
		prime->player.angle -= ROTATE_ANGLE;
	prime->player.angle = ft_normalizing(prime->player.angle);
}

void	ft_update_postion(t_prime *prime)
{
	if (prime->angle_range == 1)
	{
		ft_first_range(prime);
	}
	if (prime->angle_range == 2)
	{
		ft_second_range(prime);
	}
	if (prime->angle_range == 3)
	{
		ft_third_range(prime);
	}
	if (prime->angle_range == 4)
	{
		ft_fourth_range(prime);
	}
}
