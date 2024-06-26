/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:38:50 by antoinemura       #+#    #+#             */
/*   Updated: 2024/06/02 11:08:19 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
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
	mlx_image_t	*tiles_img[5];
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
	E_GLOBAL,
	E_OPEN,
	E_MAPEMPTY,
	E_MAPWIDTH,
	E_MAPEDGES,
	E_FINISHABLE,
	E_INVALID_CHAR,
	E_COLLECTIBLE,
	E_EXIT,
	E_PLAYER,
}	t_errno;

extern t_errno	g_eno;

typedef enum e_bloc
{
	E_PLANCHE = 0,
	E_BRIQUE = 1,
	E_FLEUR = 2,
	E_ECHELLE = 3,
	E_TNT = 4
}	t_bloc;

typedef enum e_ok
{
	E_OK = 0,
	E_ERR = 1
}	t_ok;

typedef struct s_queue_node
{
	int					x;
	int					y;
	struct s_queue_node	*next;
}	t_queue_node;

typedef struct s_queue
{
	t_queue_node	*front;
	t_queue_node	*rear;
}	t_queue;

typedef struct s_bfs_vars
{
	int		directions[4][2];
	t_ok	**visited;
	t_queue	q;
	int		consumables_found;
	t_ok	exit_found;
}	t_bfs_vars;

// MODEL

// counter
t_ok			new_counter(t_game *game);
void			free_counter(t_counter *counter);

// game
t_ok			new_game(char *filename, t_game *game);
void			free_game(t_game game);

// graphics
void			new_graphics(t_game *game);
void			free_graphics(t_graphics *graph);
t_ok			imgs_to_window(t_game game);
mlx_instance_t	*get_img_by_pos(t_game *game, int y, int x, t_bloc bloc);
void			set_images(t_graphics **graph);
void			place_image(t_game *game, int x, int y, t_bloc img_type);
void			place_tile(t_game *game, int i, int j);

// map
t_ok			new_map(int fd, t_game *game, int nb_line);
void			free_map(t_map *map);

// player
void			new_player(t_game *game);
void			free_player(t_player *player);

// UTILS

char			*gnl_and_trim(int fd);
void			my_keyhook(mlx_key_data_t keydata, void *game);
void			t_exit(t_game game);

// VALIDATE
t_ok			is_rectangle(t_game game);
t_ok			is_closed(t_game game);
t_ok			is_finishable(t_game game);
t_ok			count_collectible(t_game game);
void			enqueue(t_queue *q, int x, int y);
t_queue_node	*dequeue(t_queue *q);
t_ok			**init_visited(int hauteur, int largeur);
void			free_visited(t_ok **visited, int hauteur);
t_ok			bfs(t_game game);

#endif
