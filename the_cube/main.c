/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:06:02 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/12/31 13:39:41 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"

int main (int ac, char **av)
{
	t_parse *parse;
	t_prime prime;
	// parse = ft_parcing(ac, av);
	parse = ft_virtual_parcing(ac, av);
	if(parse == NULL)
		return (1);
	
	ft_initialize(&prime, parse);



	if(ft_rendering(&prime) == false)
	{
		// free all 
		return (1);
	}
	
	
	return (0);
}




