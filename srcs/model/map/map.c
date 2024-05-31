/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:59:09 by antoinemura       #+#    #+#             */
/*   Updated: 2024/05/30 18:07:16 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

t_map	*new_map(int hauteur, int largeur)
{
	int		y;
	t_map	*map;

	y = 0;
	map = ft_calloc(1, sizeof(t_map *));
	map->hauteur = hauteur;
	map->largeur = largeur;
	map->tiles = ft_calloc(hauteur, sizeof(int *));
	while (y < hauteur)
	{
		map->tiles[y] = ft_calloc(largeur, sizeof(int));
		y++;
	}
	return (map);
}

int	ber_to_map(int fd, char *filename, t_game **game)
{
	int		y;
	int		nb_line;
	char	*line;
	
	nb_line = wc_l(filename);
	(*game)->map = ft_calloc(1, sizeof(t_map *));
	(*game)->map->tiles = ft_calloc(nb_line + 1, sizeof(char *));
	line = gnl_and_trim(fd);
	(*game)->map->largeur = (int)ft_strlen(line);
	y = 0;
	while (line != NULL)
	{
		(*game)->map->tiles[y] = ft_str_split_char(line);
		line = gnl_and_trim(fd);
		y++;
	}
	(*game)->map->hauteur = y;
	return (E_OK);
}

void	free_map(t_map *map)
{
	int	y;

	y = 0;
	while (y < map->hauteur)
	{
		free(map->tiles[y]);
		y++;
	}
	free(map->tiles);
	free(map);
}

