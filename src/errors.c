/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 12:41:05 by ryatan            #+#    #+#             */
/*   Updated: 2025/10/26 21:48:38 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ptypes.h"

void	ft_handle_error(void)
{
	ft_putstr("Error\n");
	exit(1) ;
}

void	ft_handle_dict_error(void)
{
	ft_putstr("Dict Error");
	ft_putchar('\n');
	exit(1) ;
}

void	ft_check_if_num(char *s)
{
	int	i;
	int	err;

	i = 0;
	err = 0;
	if (s[0] == '\0')
    	ft_handle_error();
	if (s[0] == '-')
		ft_handle_error();
	if (s[0] == '0' && s[1] != '\0')
		ft_handle_error();
	if (ft_len(s) > 37)
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
