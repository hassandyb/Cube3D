/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:06:02 by hed-dyb           #+#    #+#             */
/*   Updated: 2024/01/20 18:11:10 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"



void ft_init_parse(t_parse *parse)
{
	parse->map = NULL;
	parse->no = NULL;
	parse->so = NULL;
	parse->we = NULL;
	parse->ea = NULL;
	parse->f = -1;
	parse->c = -1;
}






int main (int ac, char **av)
{
	t_parse parse;
	// t_prime prime;
	ft_init_parse(&parse);
	ft_parse(ac, av, &parse);
	while(1)
		sleep(5);
	// ft_initialize(&prime, &parse);
	// ft_rendering(&prime);
	
	return (0);
}




