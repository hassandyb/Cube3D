/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:50:40 by hed-dyb           #+#    #+#             */
/*   Updated: 2024/01/18 15:08:56 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

bool	ft_collision_case_1(t_prime *prime, int i, int j)
{
	int		cur_i;
	int		cur_j;
	char	**map;

	map = prime->parse->map;
	cur_i = prime->player.px / IMG_SIZE;
	cur_j = prime->player.py / IMG_SIZE;
	if (map[j][i] == '0' && i == cur_i + 1 && j == cur_j + 1)
	{
		if (map[cur_j][i] == '1' && map[j][cur_i] == '1')
			return (true);
	}
	return (false);
}

bool	ft_collision_case_2(t_prime *prime, int i, int j)
{
	int		cur_i;
	int		cur_j;
	char	**map;

	map = prime->parse->map;
	cur_i = prime->player.px / IMG_SIZE;
	cur_j = prime->player.py / IMG_SIZE;
	if (map[j][i] == '0' && i == cur_i - 1 && j == cur_j + 1)
	{
		if (map[cur_j][i] == '1' && map[j][cur_i] == '1')
			return (true);
	}
	return (false);
}

bool	ft_collision_case_3(t_prime *prime, int i, int j)
{
	int		cur_i;
	int		cur_j;
	char	**map;

	map = prime->parse->map;
	cur_i = prime->player.px / IMG_SIZE;
	cur_j = prime->player.py / IMG_SIZE;
	if (map[j][i] == '0' && i == cur_i - 1 && j == cur_j - 1)
	{
		if (map[cur_j][i] == '1' && map[j][cur_i] == '1')
			return (true);
	}
	return (false);
}

bool	ft_collision_case_4(t_prime *prime, int i, int j)
{
	int		cur_i;
	int		cur_j;
	char	**map;

	map = prime->parse->map;
	cur_i = prime->player.px / IMG_SIZE;
	cur_j = prime->player.py / IMG_SIZE;
	if (map[j][i] == '0' && i == cur_i + 1 && j == cur_j - 1)
	{
		if (map[j][cur_i] == '1' && map[cur_j][i] == '1')
			return (true);
	}
	return (false);
}

bool	ft_wall_collision_case(t_prime *prime, int i, int j)
{
	if (ft_collision_case_1(prime, i, j) == true)
		return (true);
	if (ft_collision_case_2(prime, i, j) == true)
		return (true);
	if (ft_collision_case_3(prime, i, j) == true)
		return (true);
	if (ft_collision_case_4(prime, i, j) == true)
		return (true);
	return (false);
}
