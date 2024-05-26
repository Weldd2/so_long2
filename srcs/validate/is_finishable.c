/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_finishable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:00:42 by antoinemura       #+#    #+#             */
/*   Updated: 2024/05/26 16:22:09 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	is_finishable(char *filename)
{
	int		hauteur;
	int		largeur;
	t_map	*map;

	if (get_hauteur_largeur(filename, &hauteur, &largeur) == E_ERR)
		return (E_ERR);
	map = new_map(hauteur, largeur);
	fill_map(filename, map);
	for (int i = 0; i < map->hauteur; i++)
	{
		for (int j = 0; j < map->largeur; j++)
			ft_printf("%c", map->tiles);
		ft_printf("%c", '\n');
	}
	return (free_map(map), E_OK);
}
