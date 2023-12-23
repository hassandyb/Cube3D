/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:06:02 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/12/23 20:09:52 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"

int main (int ac, char **av)
{
	t_parse *parse;
	// parse = ft_parcing(ac, av);
	parse = ft_virtual_parcing(ac, av);
	if(parse == NULL)
	{
		// free all 
		return (1);
	}
	t_prime prime;
	if(ft_do_ray_casting(&prime, parse) == false)
	{
		// free all 
		return (1);
	}



	// if(ft_do_rendering(parse) == false)
	// {
	// 	// free all 
	// 	return (1);
	// }
	
	
	return (0);
}