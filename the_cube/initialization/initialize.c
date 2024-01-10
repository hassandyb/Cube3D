/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:55:55 by hed-dyb           #+#    #+#             */
/*   Updated: 2024/01/09 14:10:08 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_initialize_rows_cols(t_prime *prime)
{
	int	i;
	int j;

	i = 0;
	j = 0;

	while(prime->parse->map[0][i])
		i++;
	prime->cols = i;
	while(prime->parse->map[j])
		j++;
	prime->lines = j;

}

void ft_initialize_player_angle(t_prime *prime)
{
	int i;
	int j;
	char **tmp;

	i = -1;
	j = -1;
	tmp = prime->parse->map;
	while(tmp[++j])
	{
		i = -1;
		while(tmp[j][++i])
		{
			if(tmp[j][i] == 'N')
				prime->player.angle = 3 * (M_PI / 2);
			if(tmp[j][i] == 'S')
				prime->player.angle = M_PI / 2;
			if(tmp[j][i] == 'E')
				prime->player.angle = 0;
			if(tmp[j][i] == 'W')
				prime->player.angle = M_PI;
		}
	}
}

void	ft_initialize_player_cord(t_prime *prime)
{
	int i;
	int j;
	char **tmp = prime->parse->map;
	bool brk = false;

	i = -1;
	j = -1;
	while(tmp[++j])
	{
		i = -1;
		while(tmp[j][++i])
		{
			if(tmp[j][i] == 'N' || tmp[j][i] == 'S' || tmp[j][i] == 'E' || tmp[j][i] == 'W')
			{
				brk = true;
				break;
			}		
		}
		if(brk == true)
			break;	
	}
	prime->player.px = (i * IMG_SIZE) + (IMG_SIZE / 2);
	prime->player.py = (j * IMG_SIZE) + (IMG_SIZE / 2);
	prime->parse->map[j][i] = '0';
}

void ft_initialize(t_prime *prime, t_parse *parse)
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
	
	//  if it is working without initialization remove them .......
	prime->ray.hit = true;
	prime->ray.r_angle = 0;
	prime->ray.len = 0;
	prime->ray.deltax = 0;
	prime->ray.deltay = 0;
	prime->ray.first = 0;
	prime->ray.periodic = 0;
	prime->ray.l_len = 0;
	prime->ray.c_len = 0;

	


}