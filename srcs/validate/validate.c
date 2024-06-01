/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:55:20 by antoinemura       #+#    #+#             */
/*   Updated: 2024/06/01 14:59:42 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_ok	validate(t_game game)
{
	if (is_rectangle(game) == E_ERR)
		return (g_eno = E_MAPWIDTH, E_ERR);
	if (is_closed(game) == E_ERR)
		return (g_eno = E_MAPEDGES, E_ERR);
	if (count_collectible(game) == E_ERR)
		return (E_ERR);
	if (is_finishable(game) == E_ERR)
		return (g_eno = E_FINISHABLE, E_ERR);
	return (E_OK);
}
