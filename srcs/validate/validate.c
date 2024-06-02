/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:55:20 by antoinemura       #+#    #+#             */
/*   Updated: 2024/06/01 23:10:13 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_ok	validate(t_game game)
{
	if (is_rectangle(game) == E_ERR)
		return (g_eno = E_MAPWIDTH, E_ERR);
	if (is_closed(game) == E_ERR)
		return (g_eno = E_MAPEDGES, E_ERR);

	return (E_OK);
}
