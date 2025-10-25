/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 12:41:05 by ryatan            #+#    #+#             */
/*   Updated: 2025/10/25 22:59:36 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ptypes.h"

void	ft_handle_error(void)
{
	ft_putstr("Error");
	ft_putchar('\n');
}

void	ft_handle_dict_error(void)
{
	ft_putstr("Dict Error");
	ft_putchar('\n');
}

void	ft_check_if_num(char *s)
{
	int	i;
	int	err;

	i = 0;
	err = 0;
	if (s[0] == '-')
		ft_handle_error();
	while (s[i] && err == 0)
	{
		if ((!(s[i] >= '0' && s[i] <= '9')))
		{
			ft_handle_error();
			err++;
		}
		i++;
	}
}
