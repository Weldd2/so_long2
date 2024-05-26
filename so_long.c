/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:36:11 by antoinemura       #+#    #+#             */
/*   Updated: 2024/05/26 15:16:46 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

t_errno				g_eno;

static void	printerr(void)
{
	static const char	*errstr[] = {\
		[E_OPEN] = "Could not open file.", \
		[E_MAPEMPTY] = "Map is empty", \
		[E_MAPWIDTH] = "Map has lines of different width.", \
		[E_MAPEDGES] = "Map is not surrounded by walls.", \
		[E_FINISHABLE] = "Map is not finishable.", \
	};
	if (errstr[g_eno])
		ft_printf("%s\n", errstr[g_eno]);
}

int	main(int argc, __attribute__((unused)) char **argv)
{
	__attribute__((unused)) t_game	*game;
	if (argc != 2)
		return (g_eno = E_OPEN, printerr(), EXIT_FAILURE);
	if (validate(argv[1]) == E_ERR)
		return (printerr(), EXIT_FAILURE);
	// game = new_game(hauteur, largeur);
	return (E_OK);
}