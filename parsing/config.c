#include "cube.h"

int    fill_informations(t_game *game)
{
    int i = 0;
    int j = 0;
    char *line, *trimmed;
    while (game->map_informations[i])
    {
        line = game->map_informations[i];
            
            if (ft_strncmp(game->map_informations[i], "NO ", 3) == 0)
            {
                if (game->north_texture != NULL)
                    return (perror("Error\nDuplicate north texture\n"), 1);
                game->north_texture = ft_strtrim((line + 3));
            }
            else if (ft_strncmp(game->map_informations[i], "SO ", 3) == 0)
            {
                if (game->south_texture != NULL)
                    return (perror("Error\nDuplicate south texture\n"), 1);
                game->south_texture = ft_strtrim(line + 3);
            }
            else if (ft_strncmp(game->map_informations[i], "WE ", 3) == 0)
            {
                if (game->west_texture != NULL)
                    return (perror("Error\nDuplicate west texture\n"), 1);
                game->west_texture = ft_strtrim(line + 3);
            }
            else if (ft_strncmp(game->map_informations[i], "EA ", 3) == 0)
            {
                if (game->east_texture != NULL)
                    return (perror("Error\nDuplicate east texture\n"), 1);
                game->east_texture = ft_strtrim(line + 3);
            }
            else if (ft_strncmp(game->map_informations[i], "F ", 2) == 0)
            {
                if (game->floor_color != -1)
                    return (perror("Error\nDuplicate floor color\n"), 1);
                trimmed = ft_strtrim(line + 2);
                game->floor_color = parse_color(trimmed);
            }    
            else if (ft_strncmp(game->map_informations[i], "C ", 2) == 0)
            {
                if (game->ceiling_color != -1)
                    return (perror("Error\nDuplicate ceiling color\n"), 1);
                trimmed = ft_strtrim(line + 2);
                game->ceiling_color = parse_color(trimmed);
            }    
            else if (ft_strlen(line) > 0)
                return (perror("Error\nInvalid information\n"), 1);
            i++;
    }
    if (!game->north_texture || !game->south_texture || 
        !game->west_texture || !game->east_texture || 
        game->floor_color == -1 || game->ceiling_color == -1)
        return (perror("Error\nMissing required configuration\n"), 1);
    return (0);
}