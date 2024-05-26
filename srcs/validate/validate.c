/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:55:20 by antoinemura       #+#    #+#             */
/*   Updated: 2024/05/26 16:23:16 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	validate(char *filename)
{
	if (file_exists(filename) == E_ERR)
		return (g_eno = E_OPEN, E_ERR); 
	if (is_rectangle(filename) == E_ERR)
		return (g_eno = E_MAPWIDTH, E_ERR);
	if (is_closed(filename) == E_ERR)
		return (g_eno = E_MAPEDGES, E_ERR);
	if (is_finishable(filename) == E_ERR)
		return (g_eno = E_FINISHABLE, E_ERR);
	return (E_OK);
}
