/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:55:53 by hed-dyb           #+#    #+#             */
/*   Updated: 2024/01/01 12:01:23 by hed-dyb          ###   ########.fr       */
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
        "  111111111   ",
        "  100110001   ",
        " 1000100001   ",
        "100000000001  ",
        " 10000E000001 ",
        "  100000000001",
        "  111111111110",
		
    };
	int i = 0;
	int j = 0;
	while (j < 7)
	{
		i = 0;
		parse->map[j] = malloc( (14 + 1) * sizeof(char) );
		while(i < 14)
		{

			parse->map[j][i] = mapData[j][i];
			i++;
			// if(i == 0)
				
		}
		parse->map[j][i] = '\0';
		j++;
		
	}
	parse->map[j] = NULL;

	return (parse);
}
