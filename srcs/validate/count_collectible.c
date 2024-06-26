/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_collectible.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:23:47 by antoinemura       #+#    #+#             */
/*   Updated: 2024/06/01 23:10:13 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_ok	count_collectible(t_game game)
{
	if (game.counter == NULL)
		return (g_eno = E_GLOBAL, E_ERR);
	if (game.counter->c_count < 1)
		return (g_eno = E_COLLECTIBLE, E_ERR);
	if (game.counter->e_count != 1)
		return (g_eno = E_EXIT, E_ERR);
	if (game.counter->p_count != 1)
		return (g_eno = E_PLAYER, E_ERR);
	return (E_OK);
}
