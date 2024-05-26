/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:06:05 by antoinemura       #+#    #+#             */
/*   Updated: 2024/05/26 14:39:38 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

t_player	*new_player()
{
	t_player	*player;

	ft_calloc(1, sizeof(t_player *));
	player->p_y = -1;
	player->p_x = -1;
	return (player);
}

void	free_player(t_player *player)
{
	free(player);
}

void	set_player_coords(t_player *player, int x, int y)
{
	player->p_y = y;
	player->p_x = x;
}
