/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboussel <oboussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 10:02:27 by oboussel          #+#    #+#             */
/*   Updated: 2025/09/04 14:57:12 by oboussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	add_alloc(t_alloc **head, char *content)
{
	t_alloc	*new;
	t_alloc	*current;

	new = calloc(sizeof(t_alloc), 1);
	new->pointer = content;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	current = *(head);
	while (current->next)
		current = current->next;
	current->next = new;
}

void	lstclear(t_alloc *head)
{
	t_alloc	*tmp;

	while (head)
	{
		free(head->pointer);
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void	*ft_malloc(size_t bytes, int action)
{
	static t_alloc	*head;
	void			*alloc;

	if (action == ALLOC)
	{
		alloc = calloc(bytes, 1);
		if (!alloc)
		{
			lstclear(head);
			return (NULL);
		}
		add_alloc(&head, alloc);
		return (alloc);
	}
	else
		lstclear(head);
	return (NULL);
}
