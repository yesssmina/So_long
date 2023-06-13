/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:18:43 by sanaggar          #+#    #+#             */
/*   Updated: 2023/06/08 17:17:04 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./GNL/get_next_line.h"
# include "./GNL/get_next_line_bonus.h"
# include "./Libft/libft.h"
# include "./Printf/ft_printf.h"
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>

//typedef struct	s_pos
//{
//	int		x;
//	int		y;
//}				t_pos;

typedef struct	s_data
{
	int	nb_collectible;
	int	nb_exit;
	int	nb_player;
	int check_nb_collectible;
	int	coor_player_x;
	int	coor_player_y;
}				t_data;

typedef struct 	s_point 
{
    int 		x;
    int 		y;
} 				t_point;

typedef struct 		s_map	
{
	char	**map;
	char	**copie;
}					t_map;

int	check_size(char **map, t_point *point);
int	check_wall(char **map, t_point	*pos);
void	check_way(char **map, t_point size, t_point cur, t_data *data);
int	check_map(char **map, t_data *data, t_point *point);
int	check_check_way(char **map, t_point	size, t_point cur, t_data *data);
int	check_check_map(char **map, t_data *data, t_point *point);
int	check_parsing(t_map map, t_data *data, t_point size, t_point cur);
char **allocation_map(int nb_ligne, int nb_colonne);
int	egal_ECP1or0(char **map, int y, int x, t_data *data);
void	ft_map_et_map_copie(t_map *map, int fd);