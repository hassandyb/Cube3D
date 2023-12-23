/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:55:53 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/12/23 20:02:12 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing/parcing.h"


       


t_parse  *ft_virtual_parcing(int ac, char **av)
{
	t_parse *parse;
	(void) ac;
	(void) av;
	parse = malloc(sizeof(t_parse));
	parse->map = malloc( (7 + 1) * sizeof(char*) );
	char mapData[7 + 1][14 + 1] = 
	{
        "  1111111   ",
        "  100110001   ",
        " 1000100001   ",
        "100000000001  ",
        " 10000N000001 ",
        "  100000000001",
        "  111111111111"
    };

	for (int j = 0; j <7; j++ )
	{
		parse->map[j] = malloc( (14 + 1) * sizeof(char) );
		for(int i = 0; i < 14; i++)
		{

			parse->map[j][i] = mapData[j][i];
			if(i == 0)
				parse->map[j][14] = '\0';
		}
		
	}
	parse->map[7] = NULL;

	return (parse);
}
