/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboussel <oboussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 10:03:22 by oboussel          #+#    #+#             */
/*   Updated: 2025/09/01 11:52:21 by oboussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../get_next_line/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define FREE 1
# define ALLOC 0

typedef struct s_game
{
	char	**map;
	char	**map_informations;
	int		fd;
	int		number_lines;
	char	*map_file_name;
	char	orientation_character;
	int		player_x;
	int		player_y;
	int		line_map;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		floor_color;
	int		ceiling_color;

}			t_game;

char		**ft_split(char const *s, char c);
void		free_double_ptr(char **split);
void		free_split(char **array, size_t j);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(char *s1, char *s2);
void		ft_bzero(void *s, size_t n);
char		*ft_strncpy(char *dst, const char *src, size_t n);
int			ft_atoi(char *str);
int			check_empty_lines_map(t_game *game);
int			check_holes(t_game *game);
int			fill_informations(t_game *game);
int			check_characters(t_game *game);
char		*ft_strtrim(char *str);
void		number_of_lines(t_game *game);
int			open_file(t_game *game);
void		read_map(t_game *game);
int			player_or_zero(char c);
int			check_surrounded_walls(t_game *game);
int			parse_color(char *str);

#endif