/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:08:02 by hed-dyb           #+#    #+#             */
/*   Updated: 2024/01/17 21:44:25 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

bool	ft_valid_i(t_prime *prime, double pt_x)
{
	unsigned int	i;

	i = pt_x / IMG_SIZE;
	if (i < 0 || i >= prime->cols)
	{
		prime->ray.l_len = 0;
		return (false);
	}
	return (true);
}

bool	ft_valid_j(t_prime *prime, double pt_y)
{
	unsigned int	j;

	j = pt_y / IMG_SIZE;
	if (j < 0 || j >= prime->lines)
	{
		prime->ray.c_len = 0;
		return (false);
	}
	return (true);
}

bool	ft_is_intersection_point(t_prime *prime, double pt_x, double pt_y)
{
	unsigned int	i;
	unsigned int	j;

	i = pt_x / IMG_SIZE;
	j = pt_y / IMG_SIZE;
	if (i < 0 || i >= prime->cols)
		return (true);
	if (j < 0 || j >= prime->lines)
		return (true);
	if (prime->parse->map[j][i] == '1' || \
		prime->parse->map[j][i] == ' ' || prime->parse->map[j][i] == '\0')
		return (true);
	return (false);
}

void	ft_final_update(t_prime *prime)
{
	if (prime->ray.l_len == 0)
	{
		prime->ray.len = prime->ray.c_len;
		return ;
	}
	if (prime->ray.c_len == 0)
	{
		prime->ray.len = prime->ray.l_len;
		return ;
	}
	if (prime->ray.l_len >= prime->ray.c_len)
		prime->ray.len = prime->ray.c_len;
	else
		prime->ray.len = prime->ray.l_len;
}
