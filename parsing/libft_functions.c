#include "cube.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (s1[i] == '\0' || s2[i] == '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
		return (-1);
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (!ft_isdigit(str[i]))
		return (-1);
	while (str[i] && ft_isdigit(str[i]))
	{
		if (result > (2147483647 - (str[i] - '0')) / 10)
			return (-1);
		result = result * 10 + (str[i++] - '0');
	}
	while (str[i])
		if (!ft_isspace(str[i++]))
			return (-1);
	return ((int)result);
}

char *ft_strtrim(char *str)
{
    int i = 0;
    int len;
    char *trimmed;

    if (str == NULL)
        return (NULL);
        
    while (str[i] && str[i] == ' ')
        i++;

    len = ft_strlen(str + i);
    trimmed = malloc(len + 1);
    if (trimmed == NULL)
        return (NULL);

    strcpy(trimmed, str + i);//jib dialk
    
    return (trimmed);
}

