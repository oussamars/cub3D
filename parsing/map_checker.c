#include "cube.h"

int check_empty_lines_map(t_game *game)
{
    int i;

    i = 0;
    while (game->map[i])
    {
        if (game->map[i][0] == '\0')
            return (perror("Error\nEmpty line in the map\n"), 1);
        i++;
    }
    return (0);
}

int check_holes(t_game *game)
{
    for (int i = 0; game->map[i]; i++)
    {
        for (int j = 0; game->map[i][j]; j++)
        {
            if (game->map[i][j] == '0' || game->map[i][j] == 'N' ||
                game->map[i][j] == 'S' || game->map[i][j] == 'E' ||
                game->map[i][j] == 'W')
                {
                    if (i == 0 || game->map[i - 1][j] == ' ' || j > ft_strlen(game->map[i-1]))
                        return (perror("Error\nMap is not closed\n"), 1);
                    if (game->map[i + 1] == NULL || game->map[i + 1][j] == ' ')
                        return (perror("Error\nMap is not closed\n"), 1);
                    if (j == 0 || game->map[i][j - 1] == ' ')
                        return (perror("Error\nMap is not closed\n"), 1);
                    if (game->map[i][j + 1] == '\0' || game->map[i][j + 1] == ' ')
                        return (perror("Error\nMap is not closed\n"), 1);
                }
        }
    }
    return (0);
}

int check_characters(t_game *game)
{
    int count_orientation_caracter;

    count_orientation_caracter = 0;
    for (int i = 0; game->map[i]; i++)
    {
        for (int j = 0; game->map[i][j]; j++)
        {
            if (game->map[i][j] != '0' && game->map[i][j] != '1' &&
                game->map[i][j] != 'N' && game->map[i][j] != 'S' &&
                game->map[i][j] != 'E' && game->map[i][j] != 'W' &&
                game->map[i][j] != ' ')
                return (perror("Error\nWrong charcter\n"), 1);
            if (game->map[i][j] == 'N' || game->map[i][j] == 'S'||
                game->map[i][j] == 'E' || game->map[i][j] == 'W')
                {
                    game->orientation_character = game->map[i][j];
                    game->player_x = j;
                    game->player_y = i;
                    count_orientation_caracter++;
                }
        }
    }
    if (count_orientation_caracter != 1)
        return (perror("Error\nOrientation character\n"), 1);
    return (0);
}

int check_surrounded_walls(t_game *game)
{//replace for loop with while loop
    int i;
    int last_row = 0;
    while (game->map[last_row])
        last_row++;
    last_row--;
    for (i = 0; game->map[0][i]; i++)
    {
        if (game->map[0][i] != '1' && game->map[0][i] != ' ')
            return (perror("Error\nMap not surrounded by walls\n"), 1);
    }
    for (i = 0; game->map[last_row][i]; i++)
    {
        if (game->map[last_row][i] != '1' && game->map[last_row][i] != ' ')
            return (perror("Error\nMap not surrounded by walls\n"), 1);
    }
    for (i = 0; game->map[i]; i++)
    {
        if (game->map[i][0] != '1' && game->map[i][0] != ' ')
            return (perror("Error\nMap not surrounded by walls\n"), 1);
    }
    for (i = 0; game->map[i]; i++)
    {
        if (game->map[i][ft_strlen(game->map[i]) - 1] != '1' && game->map[i][ft_strlen(game->map[i]) - 1] != ' ')
            return (perror("Error\nMap not surrounded by walls\n"), 1);
    }
    return (0);
}

