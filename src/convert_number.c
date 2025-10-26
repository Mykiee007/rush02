/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:04:53 by mvelasqu          #+#    #+#             */
/*   Updated: 2025/10/25 22:59:44 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ptypes.h"

int	ft_group_count(char *str, char groups[13][4])
{
	int group_count;
	int len;
	int start;
    int size;
    int i;

    group_count = 0;
    len = ft_len(str);
	while (len > 0)
	{
		start = len - 3;
		if (start < 0)
			start = 0;
		size = len - start;
		i = 0;
		while (i < size)
		{
			groups[group_count][i] = str[start + i];
			i++;
		}
		groups[group_count][i] = '\0';

		len -= 3;
		group_count++;
	}
	return (group_count);
}

void	ft_power_str(int group, char *nbr)
{
	int zeros; 
    int i;

    i = 1;
    zeros = group * 3;
	nbr[0] = '1';
	while (zeros > 0)
	{
		nbr[i] = '0';
		zeros--;
        i++;
	}
	nbr[i] = '\0';
}

void	ft_convert_3digits(int nb)
{
	if (nb == 0)
		return;
	if (ft_search_content(nb, fn))
	{
		ft_putstr(ft_search_content(nb, fn));
		return ;
	}
	if (nb >= 100)
	{
		ft_putstr(ft_search_content(nb / 100, fn));
		ft_putchar(' ');
		ft_putstr(ft_search_content(100, fn));
		if (nb % 100)
			ft_putchar(' ');
		nb %= 100;
	}
	if (nb >= 20)
	{
		ft_putstr(ft_search_content((nb / 10) * 10, fn));
		if (nb % 10)
		{
			ft_putchar(' ');
			ft_putstr(ft_search_content(nb % 10), fn);
		}
	}
	else if (nb > 0)
	{
		ft_putstr(ft_search_content(nb, fn));
	}
}

void	ft_number_to_word(char *str)
{
	char groups[13][4];
    char power_str[50];
	int group_count;
	int i;
    int nbr;

	if (str[0] == '\0')
	{
		ft_putstr(ft_search_content('0', fn));
		return ;
	}
	group_count = ft_group_count(str, groups);
	i = group_count - 1;
    
	while (i >= 0)
	{
        nbr = ft_atoi(groups[i]);
		if (nbr != 0)
		{
			ft_convert_3digits(nbr);
			if (i > 0)
			{		
				ft_power_str(i, power_str);
				ft_putchar(' ');
				ft_putstr(ft_search_content(power_str, fn));
				if (i != 0 || nbr != 0)
					ft_putchar(' ');
			}
		}
		i--;
	}
}