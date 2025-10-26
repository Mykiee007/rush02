/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 11:08:25 by ryatan            #+#    #+#             */
/*   Updated: 2025/10/25 23:00:01 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ptypes.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	ft_len(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_strcmp (char *s1, char *s2)
{
	int	i;

	i = 0;
	while(s1[i] != '\0' && s2[1] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

char	*ft_strdup(char	*str)
{
	char	*dup;
	int		i;

	i = 0;
	dup = malloc((sizeof(char) * ft_len(str)) + 1);
	if (!dup)
		return (NULL);
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int ft_atoi(char *str)
{
    int i;
    int result;

    i = 0;
    result = 0;
    while (str[i] != '\0')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result);
}

void ft_itoa(int nb, char *str)
{
	int i;
	int temp;
	int len;

	if (nb == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return ;
	}
	len = 0;
	temp = nb;
	while (temp > 0)
	{
		temp /= 10;
		len ++;
	}
	str[len] = '\0';
	i = len - 1;
	while (nb > 0)
	{
		str[i] = (nb % 10) + '0';
		nb /= 10;
		i--;
	}
}

int ft_skip_line(char *content, int i)
{
	while (content[i] && content[i]) != '\n'
		i++;
	if (content[i] =='\n')
		i++;
	return (i);
}

/*========testing
#include <stdio.h>
int	main(void)
{
	char *str = "hello";
	char *new;

	new = ft_strdup(str);
	printf("%s\n", new);
}
*/
