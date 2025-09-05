/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboussel <oboussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 10:05:03 by oboussel          #+#    #+#             */
/*   Updated: 2025/09/05 15:48:58 by oboussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

char	*ft_strtrim(char *str)
{
	int		start;
	int		end;
	int		len;
	char	*trimmed;

	if (str == NULL)
		return (NULL);
	start = 0;
	while (str[start] && str[start] == ' ')
		start++;
	end = ft_strlen(str) - 1;
	while (end > start && str[end] == ' ')
		end--;
	len = end - start + 1;
	trimmed = ft_malloc(len + 1, ALLOC);
	if (trimmed == NULL)
		return (NULL);
	ft_strncpy(trimmed, str + start, len);
	trimmed[len] = '\0';
	return (trimmed);
}

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	if (!dst || !src)
		return (NULL);
	i = 0;
	while (src[i] && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
