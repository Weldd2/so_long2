/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:00:11 by antoinemura       #+#    #+#             */
/*   Updated: 2024/06/01 23:10:13 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

int	get_hauteur_largeur(char *filename, int *hauteur, int *largeur)
{
	int		fd;
	char	*line;
	int		ligne;

	ligne = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (E_ERR);
	line = gnl_and_trim(fd);
	if (line != NULL)
		*largeur = (int)ft_strlen(line);
	else
		return (close(fd), E_ERR);
	while (line != NULL)
	{
		ligne++;
		free(line);
		line = gnl_and_trim(fd);
	}
	*hauteur = ligne;
	return (close(fd), E_OK);
}
