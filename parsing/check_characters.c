/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboussel <oboussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:52:26 by oboussel          #+#    #+#             */
/*   Updated: 2025/09/01 11:52:27 by oboussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	is_orientation_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	player_or_zero(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	check_characters(t_game *game)
{
	int	count_orientation_caracter;
	int	i;
	int	j;

	count_orientation_caracter = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (is_orientation_char(game->map[i][j]) == 1)
			{
				game->orientation_character = game->map[i][j];
				game->player_x = j;
				game->player_y = i;
				count_orientation_caracter++;
			}
			j++;
		}
		i++;
	}
	if (count_orientation_caracter != 1)
		return (perror("Error\nOrientation character\n"), 1);
	return (0);
}
