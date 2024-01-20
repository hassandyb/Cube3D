/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:55:55 by hed-dyb           #+#    #+#             */
/*   Updated: 2024/01/20 15:23:27 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_initialize_rows_cols(t_prime *prime)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (prime->parse->map[0][i])
		i++;
	prime->cols = i;
	while (prime->parse->map[j])
		j++;
	prime->lines = j;
}

void	ft_initialize_player_angle(t_prime *prime)
{
	if (prime->parse->p == 'N')
		prime->player.angle = 3 * (M_PI / 2);
	if (prime->parse->p == 'S')
		prime->player.angle = M_PI / 2;
	if (prime->parse->p == 'E')
		prime->player.angle = 0;
	if (prime->parse->p == 'W')
		prime->player.angle = M_PI;

}



void	ft_initialize_player_cord(t_prime *prime)
{
	int		i;
	int		j;

	i = prime->parse->py;
	j = prime->parse->px;
	prime->player.px = (i * IMG_SIZE) + (IMG_SIZE / 2);
	prime->player.py = (j * IMG_SIZE) + (IMG_SIZE / 2);
	prime->parse->map[j][i] = '0';
}

void	ft_initialize(t_prime *prime, t_parse *parse)
{
	prime->parse = parse;
	ft_initialize_rows_cols(prime);
	ft_initialize_player_angle(prime);
	ft_initialize_player_cord(prime);
	prime->fb_status = 0;
	prime->rl_status = 0;
	prime->rotate_status = 0;
	ft_update_range(prime);
	prime->mlx_ptr = NULL;
	prime->win_ptr = NULL;
	prime->img_ptr = NULL;
	prime->ad_ptr = NULL;
	prime->wall.d = (SCREEN_WID / 2) / tan(FIELD_OF_VIEW / 2);
}
