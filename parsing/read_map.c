#include "cube.h"

void read_map(t_game *game)
{
    char *line = NULL;
    int line_size;
    int line_count = 0;
    int i;
    int j;

    i = 0;
    j = 0;
    number_of_lines(game);
    game->map = malloc(sizeof(char *) * (game->number_lines - game->line_map + 1));
    game->map_informations = malloc(sizeof(char *) * (game->line_map + 1));
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
        {
            game->map_informations[j] = malloc(line_size + 1);
            strncpy(game->map_informations[j], line, line_size);//jib dialk
            game->map_informations[j++][line_size] = '\0';
        }
        else if (line_count >= game->line_map)
        {
            game->map[i] = malloc(line_size + 1);
            strncpy(game->map[i], line, line_size);//jib dialk
            game->map[i++][line_size] = '\0';
        }
        free(line);
        line = get_next_line(game->fd);
    }  
    game->map_informations[j] = NULL;
    game->map[i] = NULL;
    close(game->fd);
}