/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 21:32:09 by ryatan            #+#    #+#             */
/*   Updated: 2025/10/25 23:19:46 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ptypes.h"

void	ft_display_ll(t_node *node)
{
	while (node != NULL)
	{
		ft_putstr(node->key);
		ft_putstr("->");
		ft_putstr(node->value);
		ft_putchar('\n');
		node = node->next;
	}
}

t_node	*ft_create_node(char *key, char *value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->key = ft_strdup(key);
	if(!new_node->key)
		return (NULL);
	new_node->value = ft_strdup(value);
	if(!new_node->value)
		return (NULL);
	new_node->next = NULL;
	return(new_node);
}

void	ft_add_node(t_node **head, char *key, char *value)
{
	t_node *new = ft_create_node(key, value);
	new->next = *head;
	*head = new;
}

void	ft_free_all(t_node **head)
{
	t_node *temp;

	while (*head)
	{
		temp = (*head)->next;
		free((*head)->key);
		free((*head)->value);
		free(*head);
		*head = temp;
	}
	*head = NULL;
}
