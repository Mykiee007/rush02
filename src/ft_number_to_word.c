/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_to_word.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:04:53 by mvelasqu          #+#    #+#             */
/*   Updated: 2025/10/25 22:59:44 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ptypes.h"

int ft_to_numbers(char *str) // changing the string of numbers to integers
{
	int result;
	int i;

	i = 0
	reuslt = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++
	}
	return (result);
}

void ft_big_nbr(long nb)
{
	long power;
	long part;

	power = 1;
	while (nb / (power * 10) > 0)
		power = power * 10;

	while (power >= 1000)
	{
		if (nb >= power)
		{
			part = nb / power;
			ft_number_to_word(part);
			ft_putchar(' ');
			ft_putstr(ft_key(power));
			nb %= power;
			if (nb != 0)
				ft_putstr(" ");
		}
		power /= 1000;
	}
	if (nb > 0)
		ft_process_small(nb);
}

void ft_small_nbr(int nb)
{
	if (ft_key(nb))
		ft_putstr(ft_key(nb));
	else if (nb >= 100)
	{
		ft_putstr(ft_key(nb/100));
		ft_putchar(' ');
		ft_putstr(ft_key(100));
		if (nb % 100)
		{
			ft_putchar(' ');
			ft_small_nbr(nb % 100);
		}
	}
	else if (nb >= 20)
	{
		ft_putstr(ft_key((nb / 10) * 10));
		if (nb % 10)
		{
			ft_putchar(' ');
			ft_putstr(ft_key(nb % 10));

		}
	}
	else
	{
		ft_putstr(ft_key(nb));
	}
}

void ft_number_to_word(char *nbr)
{

	long int n;

	n = ft_to_numbers(nbr);
	if(n == 0)
		ft_key(0); // not sure what we will name this function

	if(n >= 1000)
		ft_big_nbr(n);// handles int 1000 up, still messy XD
	else
		ft_small_nbr(n);// if int < 1000. this should be okay. 
}
