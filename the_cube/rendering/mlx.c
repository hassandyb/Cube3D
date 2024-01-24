/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:28:49 by hed-dyb           #+#    #+#             */
/*   Updated: 2024/01/22 20:33:10 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_put_a_pixel(t_prime *prime, int x, int y, int color)
{
	int	pos;

	pos = (y * prime->linesize + x * (prime->bits / 8));
	*(unsigned int *)(prime->ad_ptr + pos) = color;
}

bool	ft_load_img(t_prime *prime, char *path, int car)
{
	int	width;
	int	height;
	int	bits_per_pixel;
	int	size_line;
	int	endian;

	prime->imgs[car].obj = mlx_xpm_file_to_image \
		(prime->mlx_ptr, path, &width, &height);
	if (prime->imgs[car].obj == NULL)
	{
		return (false);
	}
	prime->imgs[car].wid = width;
	prime->imgs[car].hei = height;
	prime->imgs[car].ad = mlx_get_data_addr \
		(prime->imgs[car].obj, &bits_per_pixel, &size_line, &endian);
	if (prime->imgs[car].ad == NULL)
		return (false);
	prime->imgs[car].size_line = size_line;
	prime->imgs[car].bits_per_pixel = bits_per_pixel;
	return (true);
}

bool	ft_load_textures(t_prime *prime)
{
	if (ft_load_img(prime, prime->parse->ea, EAST) == false)
		return (false);
	if (ft_load_img(prime, prime->parse->so, SOUTH) == false)
		return (false);
	if (ft_load_img(prime, prime->parse->we, WEST) == false)
		return (false);
	if (ft_load_img(prime, prime->parse->no, NORTH) == false)
		return (false);
	return (true);
}

bool	ft_init_mlx_data(t_prime *prime)
{
	int	parameter;

	prime->mlx_ptr = mlx_init();
	if (prime->mlx_ptr == NULL)
		return (false);
	prime->win_ptr = mlx_new_window \
		(prime->mlx_ptr, SCREEN_WID, SCREEN_HEI, "my window");
	if (prime->win_ptr == NULL)
		return (false);
	prime->img_ptr = mlx_new_image(prime->mlx_ptr, SCREEN_WID, SCREEN_HEI);
	if (prime->img_ptr == NULL)
		return (false);
	prime->ad_ptr = mlx_get_data_addr \
		(prime->img_ptr, &prime->bits, &prime->linesize, &parameter);
	if (prime->ad_ptr == NULL)
		return (false);
	if (ft_load_textures(prime) == false)
	{
		printf("error\nInvalid path\n");
		return (false);
	}
	return (true);
}
