/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 23:42:42 by ryatan            #+#    #+#             */
/*   Updated: 2025/10/25 23:01:08 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ptypes.h"

int	main(int argc, char **argv)
{
	char	*dict_content;
	//int	i;
	//t_node	*dict_list;

	dict_content = ft_dict_content("numbers.dict");

	//new = 0;
	if (argc < 2 || argc > 3)
		ft_handle_error();
	else
	{
		if (argc == 2)
		{
			ft_check_if_num(argv[1]);
			//TODO
			//ft_parse_content_into_list(dict_content, &dict_list);
		}
		else
		{
			ft_check_if_num(argv[2]);
			//TODO
		}
	}
	free(dict_content);
	//free(new);
	return (0);
}
