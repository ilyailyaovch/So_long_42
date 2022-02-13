/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:18:23 by rtracee           #+#    #+#             */
/*   Updated: 2022/02/13 11:08:08 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include "mlx.h"
# include <unistd.h>
# include <fcntl.h>

# define UC unsigned char
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

typedef struct s_data
{
	int		height;
	int		width;
	char	**map;
	int		i_w;
	int		i_h;
	int		p;
	int		c;
	int		e;
	int		player_x;
	int		player_y;
	int		is_col;
	int		step;
	char	*step_str;
	int		done;

	char	*player_r_img;
	char	*back_img;
	char	*wall_img;
	char	*exit_img;
	char	*collect_img;

	void	*back;
	void	*wall;
	void	*player_r;
	void	*collect;
	void	*exit;

	void	*mlx;
	void	*window;

}t_data;

/*	ft_map_create.c */
int		ft_map_processing(char *map, t_data *data);
int		ft_see_symbol(t_data data);
int		ft_see_wall(t_data data);
int		ft_see_map(t_data *data);
int		ft_error(t_data *data);

/*	ft_map_create_utils.c */
int		ft_height(char *map);
int		ft_width(char *map);
void	ft_init_image(t_data *data);
int		ft_key_exit(t_data *data);

/*	lib_utils_1.c */
void	ft_putstr(char *s);
void	ft_putchar(char c);
int		ft_kolvo(int n);
char	*ft_itoa(int n);
int		ft_strlen(const char *s);

/*	lib_utils_2.c */
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_out_gnl(int i, char **buf, char **remain);

/*	lib_utils_3.c */
int		ft_is_char(char c);
void	ft_putnbr(int n);

/*	keys_1.c */
int		ft_key(int keycode, t_data *data);
void	ft_key_a(t_data *data, int j, int i);
void	ft_key_d(t_data *data, int j, int i);
void	ft_key_w(t_data *data, int i, int j);
void	ft_key_s(t_data *data, int i, int j);

/*	keys_2.c */
int		ft_is_1(t_data *data, int i, int j);
int		ft_is_e(t_data *data, int i, int j);
int		ft_step(t_data *data);
void	ft_win(t_data *data);

/*	mlx_func.c */
void	ft_back(t_data *data);
void	ft_wall(t_data *data);
void	ft_player(t_data *data);
void	ft_collect(t_data *data);
void	ft_exit(t_data *data);

/*	movements.c */
void	ft_go_left(t_data *data, int i, int j);
void	ft_go_right(t_data *data, int i, int j);
void	ft_go_up(t_data *data, int i, int j);
void	ft_go_down(t_data *data, int i, int j);

/*	clear.c */
void	ft_clear(char **str);
void	ft_clear_mas(t_data data);
void	ft_clear_mas_val(t_data *data);

/*	gnl.c */
void	ft_gnl_in_str(char **buf, char **str, char **gnl);
void	ft_gnl_in_line(char **line, char **str, char **gnl);
int		ft_gnl(int fd, char **line);
char	*ft_g_n_l(int fd, char **line);

#endif
