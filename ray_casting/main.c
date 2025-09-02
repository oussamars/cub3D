/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 10:11:54 by imeftah-          #+#    #+#             */
/*   Updated: 2025/09/02 13:32:00 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	parsing(t_game *game, int ac, char **av)
{
	if (ac != 2)
		return (perror("Error\nYou should have the right parameters\n"), 1);
	if (check_file_name(av[1]) == 1)
		return (1);
	initialize_struct(game, av[1]);
	if (pars_map(game) == 1)
		return (1);
	return (0);
}

int	main(int ac, char *av[])
{
	t_cube	*data;
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (parsing(game, ac, av) == 1)
		return (1);
	data = ft_malloc(sizeof(t_cube), ALLOC);
	data->game = game;
	initialize(data, av[1]);
	render_all(data);
	mlx_hook(data->win, 17, 0, ft_exit, data);
	mlx_hook(data->win, 2, 1L << 0, key_check, data);
	mlx_loop(data->mlx);
}
