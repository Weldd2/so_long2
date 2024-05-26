/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:00:11 by antoinemura       #+#    #+#             */
/*   Updated: 2024/05/26 16:22:49 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

int	get_hauteur_largeur(char *filename, int *hauteur, int *largeur)
{
	int		fd;
	char	*line;
	int		ligne;

	ligne = 0;
	fd = open(filename, O_RDONLY);
	line = gnl_and_trim(fd);
	if (line != NULL)
		*hauteur = (int)ft_strlen(line);
	else
		return (close(fd), E_ERR);
	while (line != NULL)
	{
		ligne++;
		line = gnl_and_trim(fd);
	}
	*largeur = ligne;
	return (close(fd), E_OK);
}
