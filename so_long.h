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

typedef struct	s_pos
{
	int		x;
	int		y;
}				t_pos;

typedef struct	s_data
{
	int	nb_collectible;
	int	nb_exit;
	int	nb_player;
}				t_data;


typedef struct 	s_point 
{
    int 		x;				// x : Width  | x-axis
    int 		y;			// y : Height | y-axis
} 				t_point;

int	check_size(char	**map);
int	check_wall(char **map);
void	check_way(char **map, t_point size, t_point cur, t_data *data);
int	check_map(char **map);