/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 23:42:42 by ryatan            #+#    #+#             */
/*   Updated: 2025/10/26 22:06:02 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ptypes.h"

int	main(int argc, char **argv)
{
	char	*dict_content;

	if (argc < 2 || argc > 3)
		ft_handle_error();
	else
	{
		if (argc == 2)
		{
			ft_check_if_num(argv[1]);
			ft_number_to_word(argv[1], "numbers.dict");
		}
		else
		{
			ft_check_if_num(argv[2]);
			ft_number_to_word(argv[2], argv[1]);
		}
	}
	free(dict_content);
	//free(new);
	return (0);
}
