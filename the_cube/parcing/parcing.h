/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:17:16 by hed-dyb           #+#    #+#             */
/*   Updated: 2024/01/14 11:27:18 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARCING_H
# define Parcing_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>


typedef struct	s_parse
{
	char	**map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;

	// int f;
	// int c;

} t_parse;

t_parse  *ft_virtual_parcing(int ac, char **av);

# endif