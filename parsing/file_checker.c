/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboussel <oboussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 10:03:26 by oboussel          #+#    #+#             */
/*   Updated: 2025/09/01 11:45:38 by oboussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

// int	invalid_character(char c)
// {
// 	if (c != '0' && c != '1' && c != 'N' && c != 'S' && c != 'E' && c != 'W'
// 		&& c != ' ')
// 		return (1);
// 	return (0);
// }

void	number_of_lines(t_game *game)
{
	char	*line;
	int		i;
	int		map_found;
	int		valid_map_line;
	int		j;

	i = 0;
	map_found = 0;
	line = get_next_line(game->fd);
	while (line)
	{
		i++;
		game->number_lines++;
		if (ft_strlen(line) > 1)
		{
			j = 0;
			while (line[j] == ' ')
				j++;
			if (ft_strncmp(line + j, "NO ", 3) == 0 || ft_strncmp(line + j,
					"SO ", 3) == 0 || ft_strncmp(line + j, "WE ", 3) == 0
				|| ft_strncmp(line + j, "EA ", 3) == 0 || ft_strncmp(line + j,
					"F ", 2) == 0 || ft_strncmp(line + j, "C ", 2) == 0)
			{
				if (map_found == 1)
				{
					printf("the line number is %d", i);
					perror("Error\nMap should be the last element\n");
					free(line);
					exit(1);
				}
			}
			else
			{
				valid_map_line = 1;
				for (int j = 0; line[j] && line[j] != '\n'; j++)
				{
					if (line[j] != '0' && line[j] != '1' && line[j] != ' '
						&& line[j] != 'N' && line[j] != 'S' && line[j] != 'E'
						&& line[j] != 'W')
					{
						valid_map_line = 0;
						break ;
					}
				}
				if (valid_map_line)
				{
					if (map_found == 0)
					{
						map_found = 1;
						game->line_map = i;
					}
				}
				else
				{
					perror("Error\nInvalid character in the file\n");
					free(line);
					exit(1);
				}
			}
		}
		free(line);
		line = get_next_line(game->fd);
	}
	if (line == NULL && game->line_map == 0)
	{
		perror("Error\nNo map provided\n");
		exit(0);
	}
	lseek(game->fd, 0, SEEK_SET);
}

int	open_file(t_game *game)
{
	game->fd = open(game->map_file_name, O_RDONLY);
	if (game->fd < 0)
	{
		perror("Error\nOpening the map file\n");
		return (1);
	}
	return (0);
}
