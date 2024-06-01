/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:12:51 by antoinemura       #+#    #+#             */
/*   Updated: 2024/06/01 15:07:58 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

static t_ok	fill_counter(t_game *game, t_counter *counter)
{
	int			i;
	int			j;

	i = 0;
	while (i < game->map->hauteur)
	{
		j = 0;
		while (j < game->map->largeur)
		{
			if (game->map->tiles[i][j] == 'P')
				counter->p_count++;
			else if (game->map->tiles[i][j] == 'C')
				counter->c_count++;
			else if (game->map->tiles[i][j] == 'E')
				counter->e_count++;
			else if (game->map->tiles[i][j] != '0' && game->map->tiles[i][j] != '1')
				return (g_eno = E_INVALID_CHAR, E_ERR);
			j++;
		}
		i++;
	}
	game->counter = counter;
	return (E_OK);
}

t_ok	new_counter(t_game *game)
{
	t_counter	*counter;

	counter = ft_calloc(sizeof(t_counter *), 1);
	counter->c_count = 0;
	counter->e_count = 0;
	counter->p_count = 0;
	return (fill_counter(game, counter));
}

void	free_counter(t_counter *counter)
{
	free(counter);
}
