/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:17:16 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/12/23 15:40:08 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARCING_H
# define Parcing_H

#include <stdint.h>
#include <stdlib.h>



typedef struct	s_parse
{
	char	**map;
	int		x;
	int		y;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;

	// __unit32_t f;
	// __unit32_t c;

} t_parse;

t_parse  *ft_virtual_parcing(int ac, char **av);

# endif