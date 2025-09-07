/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboussel <oboussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 10:11:54 by imeftah-          #+#    #+#             */
/*   Updated: 2025/09/07 10:37:20 by oboussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	parsing(t_game *game, char **av)
{
	initialize_struct(game, av[1]);
	if (pars_map(game) == 1)
		return (close(game->fd), 1);
	close(game->fd);
	return (0);
}

int	main(int ac, char *av[])
{
	t_cube	*data;
	t_game	*game;

	if (ac != 2)
		return (write(2, "Error\nYou should have the right parameters\n", 44),
			1);
	if (check_file_name(av[1]) == 1)
		return (1);
	game = ft_malloc(sizeof(t_game), ALLOC);
	if (parsing(game, av) == 1)
		return (ft_exit(NULL), 1);
	data = ft_malloc(sizeof(t_cube), ALLOC);
	data->game = game;
	initialize(data);
	render_all(data);
	mlx_hook(data->win, 17, 0, ft_exit, data);
	mlx_hook(data->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->win, 3, 1L << 1, key_release, data);
	mlx_loop_hook(data->mlx, key_check, data);
	mlx_loop(data->mlx);
}
