/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 10:03:34 by oboussel          #+#    #+#             */
/*   Updated: 2025/09/02 10:51:18 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	fill_config(t_game *game, char *line, int *j, int line_size)
{
	game->map_informations[*j] = malloc(line_size + 1);
	ft_strncpy(game->map_informations[*j], line, line_size);
	game->map_informations[*j][line_size] = '\0';
	(*j)++;
}

void	fill_map(t_game *game, char *line, int *i, int line_size)
{
	game->map[*i] = malloc(line_size + 1);
	ft_strncpy(game->map[*i], line, line_size);
	game->map[*i][line_size] = '\0';
	(*i)++;
}

void	loop_read_map(t_game *game, int *j, int *i)
{
	char	*line;
	int		line_count;
	int		line_size;

	line_count = 0;
	line = NULL;
	line = get_next_line(game->fd);
	while (line != NULL)
	{
		line_count++;
		line_size = ft_strlen(line);
		if (line[line_size - 1] == '\n')
		{
			line_size--;
			line[line_size] = '\0';
		}
		if (line_count < game->line_map)
			fill_config(game, line, j, line_size);
		else if (line_count >= game->line_map)
			fill_map(game, line, i, line_size);
		free(line);
		line = get_next_line(game->fd);
	}
}

void	read_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	number_of_lines(game);
	game->map = malloc(sizeof(char *) * (game->number_lines - game->line_map
				+ 2));
	game->map_informations = malloc(sizeof(char *) * (game->line_map + 1));
	loop_read_map(game, &j, &i);
	game->map_informations[j] = NULL;
	game->map[i] = NULL;
	close(game->fd);
}
