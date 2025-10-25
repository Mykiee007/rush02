/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptypes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 13:42:37 by ryatan            #+#    #+#             */
/*   Updated: 2025/10/25 23:18:25 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PTYPES_H
# define PTYPES_H

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct s_node
{
	char			*key;
	char			*value;
	struct s_node	*next;
}	t_node;

t_node	*ft_create_node(char *key, char *value);
void	ft_display_ll(t_node *node);
void	ft_add_node(t_node **head, char *key, char *value);
void	ft_handle_error(void);
void	ft_handle_dict_error(void);
void	ft_check_if_num(char *s);
void	ft_putchar(char c);
void	ft_putstr(char *s);
char	*ft_strdup(char *s);
char 	*ft_dict_content(char *fn);

#endif
