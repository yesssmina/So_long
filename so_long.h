/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:18:43 by sanaggar          #+#    #+#             */
/*   Updated: 2023/06/28 01:11:04 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./Lib/GNL/get_next_line.h"
# include "./Lib/GNL/get_next_line_bonus.h"
# include "./Lib/Libft/libft.h"
# include "./Lib/Printf/ft_printf.h"
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>

typedef struct	s_data_mlx
{
	char	*path;
	char	*p_wall;
	char	*p_col;
	char	*p_pl_f;
	char	*p_pl_l;
	char	*p_pl_r;
	char	*p_pl_b;
	char	*p_ex;
	int		img_width;
	int		img_height;
	int		wid;
	int		hei;
	void	*img;
	void	*wall;
	void	*col;
	void	*player_f;
	void	*player_l;
	void	*player_r;
	void	*player_b;
	void	*exit;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		coor_x;
	int		coor_y;
	int		count_coll;
	int		nb_coll;
	int		count_mouv;
	int		check_mouv;
	int		cell_size;
}				t_data_mlx;

typedef struct	s_vars_mlx 
{
	void	*mlx;
	void	*win;
}				t_vars_mlx;


typedef struct	s_data
{
	int	nb_col;
	int	nb_exit;
	int	nb_player;
	int check_nb_col;
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
	int		nb_colones;
	int		nb_lignes;
	char	*chemin_vers_fichier;
}					t_map;

typedef struct 		s_all	
{
	t_map		*map;
	t_point		*point;
	t_data		*data;
	t_vars_mlx	*v_mlx;
	t_data_mlx	*d_mlx;
	int			x;
	int			y;
}					t_all;

int		check_size(char **map, t_point *point);
int		check_wall(char **map, t_point	*pos);
void	check_way(char **map, t_point size, t_point cur, t_data *data);
int		check_map(char **map, t_data *data, t_point *point);
int		check_check_way(char **map, t_point	size, t_point cur, t_data *data);
int		check_check_map(char **map, t_data *data, t_point *point);
int		check_parsing(t_map *map, t_data *data, t_point size, t_point cur);
char	 **allocation_map(int nb_ligne, int nb_colonne);
int		egal_ecp1or0(char **map, int y, int x, t_data *data);
void	ft_map_et_map_copie(t_map *map, int fd);
void	cacul_nb_lignes_et_colones(t_map	*dimension);
void 	ft_init(t_data *data);
void	ft_init1(t_map *map, t_data *data, t_point *cur, t_point *size);
char	*error_mess(char	*message);
int		check_ber(char *fichier);
void 	check_parsing_final(char *chemin_fichier, t_map *map);
void	do_mlx(t_all *all);
void	superpose_image(void *mlx, void *background_img, void *sur_img, int x, int y);
void	ft_init_xpm(void *mlx, t_data_mlx *img);
void	ft_init_img(t_data_mlx	*img, t_map *map, void *mlx);
void	ft_putchar(char c);
int		deal_key(int key, void	*param);
int		ft_close(int keycode, t_all *all);
void	put_texture(void *mlx, t_all *a);
void	put_texture_p(void *mlx, t_all *a);
void	position_player(t_all *all);
void	ft_mouv_player(int new_x, int new_y, t_all *all, int key);
void	reprint_map(char **map);
int		loop(t_all *all);
void	nb_coll(t_all *all);
void	check_open_xpm(void *img);
void	if_key(int key, t_all *all);
void	if_key_close(int key, t_all *all);