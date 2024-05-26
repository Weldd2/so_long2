/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:38:50 by antoinemura       #+#    #+#             */
/*   Updated: 2024/05/26 16:20:20 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <fcntl.h>

typedef struct s_counter
{
	int	c_count;
	int	e_count;
	int	p_count;
}	t_counter;

typedef struct s_player
{
	int	p_y;
	int	p_x;
}	t_player;

typedef struct s_map
{
	char	**tiles;
	int		hauteur;
	int		largeur;
}	t_map;

typedef struct s_graphics
{
	mlx_image_t	*tiles_img[4];
	mlx_t		*mlx;
}	t_graphics;

typedef struct s_game
{
	t_map		*map;
	t_graphics	*graphics;
	t_counter	*counter;
	t_player	*player;
}	t_game;

typedef enum e_errno
{
	E_OPEN,
	E_MAPEMPTY,
	E_MAPWIDTH,
	E_MAPEDGES,
	E_FINISHABLE
}	t_errno;

typedef enum e_ok
{
	E_OK = 0,
	E_ERR = 1
}	t_ok;

extern t_errno	g_eno;

// MODEL

// counter
t_counter	*new_counter();
void		free_counter(t_counter *counter);

// game
t_game	*new_game(int hauteur, int largeur);
void	free_game(t_game *game);

// graphics
t_graphics	*new_graphics(int hauteur, int largeur);
void		free_graphics(t_graphics *graph);

// map
t_map		*new_map(int hauteur, int largeur);
void		free_map(t_map *map);
int			get_hauteur_largeur(char *filename, int *hauteur, int *largeur);
int			fill_map(char *filename, t_map *map);

// player
t_player	*new_player();
void		free_player(t_player *player);
void		set_player_coords(int x, int y);

// UTILS

char	*gnl_and_trim(int fd);


// VALIDATE

int	validate(char *filename);
int	file_exists(char *filename);
int	is_rectangle(char *filename);
int	is_closed(char *filename);
int	is_finishable(char *filename);

#endif
