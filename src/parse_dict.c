/* ************************************************************************** */
/*                                                                            */ /*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:23:43 by mvelasqu          #+#    #+#             */
/*   Updated: 2025/10/25 23:00:48 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ptypes.h"

char *ft_dict_content(char *fn)
{
	int fd;
	int size;
	char *content;

	fd = open(fn, O_RDONLY);
	if (fd < 0)
	{
		ft_handle_dict_error();
		return (0);
	}
	content = (char *)malloc(1080);
	if (!content)
	{
		ft_handle_dict_error();
		free(content);
		close(fd);
		return (0);
	}
	size = read(fd, content, 1080);
	if (size < 0)
	{
		ft_handle_dict_error();
		free(content);
		close(fd);
		return (0);
	}
	content[size] = '\0';
	if(close(fd) < 0)
	{
		ft_handle_dict_error();
		free(content);
		return (0);
	}
	return (content);
}

void	ft_search_content(char *str, char *fn)
{
	char *content;
	int i;
	int j;
	char line_number[50];
	int found;
	int start;
	int end;

	content = ft_dict_content(fn);
	if (!content)
	{
		ft_handle_dict_error();
		return ;
	}

	i = 0;
	found = 0;
	while (content[i] != '\0')
	{
		j = 0;
		while (content[i] && content[i] != ':' && content[i] != '\n')
		{
			line_num[j] = content[i];
			j++;
			i++;
		}
		line_num[j] = '\0';

		if (ft_strcmp(line_num, str) == 0)
		{
			found = 1;;
			if (content[i] == ':')
				i++;
			while (content[i] == ' ')
				i++;
			start = i;
			end = i;
			while (content[end] && content[end] != '\n')
				end++;
			while (end - 1 >= start && (content[end - 1] == ' ' || content[last] == '\t'))
				last--;
			if (last < start)
			{
				ft_dict_content();
				free (content);
				return ;
			}
			while (start <= end - 1)
				{
					ft_putchar(content[start]);
					start++;
				}
			ft_putchar('\n');
		}
		i = ft_skip_line(content, i);
	}
	if (!found)
		ft_handle_dict_error();

	free(content);
}

/*
char **ft_split(char *str, char *charset)
{
	char **ret;
	int i;
	int j;
	int k;
	int steps;
	int sections;
	i = 0;
	sections = 0;
	while (str[i+1]) // ignore last
	{
	    if (!charset_contains(str[i-1], charset) && charset_contains(str[i], charset))
	        sections ++;
	    i++;
	}
	ret = malloc((sections+1)*sizeof(char*));
	if (!ret)
	    return NULL;
	printf(“pointer at %d is %p \n”, sections, ret[sections]);
	i = 0;
	j = 0;
	while (str[i])
	{
	    // current char is not a seperator, and next char isn’t
	    steps = 0;
	    while ( !charset_contains(str[i], charset) && !charset_contains(str[i+steps], charset))
	    {
	        steps++;
	        printf(“\ni = %d , steps = %d”, i, steps);
	    }
	    // there was a gap
	    if (steps > 0){
	        printf(“\n%d malloced to %d”, j, steps+1);
	        ret[j] = malloc ((steps+1) * sizeof(char*));
	        if (!ret[j])
	            return NULL;
	        k = 0;
	        while (k <= steps)
	        {
	            if (!charset_contains(str[i+k], charset))
	                printf(“\nput in to %d , %d , %c”, j, k, str[i+k]);
	                ret[j][k] = str[i+k];
	            k++;
	        }
	        j++;
	    }
	    printf(“\nincremented by %d steps”, steps);
	    i+= 1+steps;
	}
	printf(“\nthere are %d sections \n”, sections+1);
	//ret[0][0] = ‘1’;
	//ret[1][0] = ‘2’;
	//ret[2][0] = ‘3’;
	return ret;
}
*/
