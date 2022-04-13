/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:56:20 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/04/13 04:47:18 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**alloc_s(const char *s, char c)
{
	int		index;
	char	**string;
	int		n_string;
	int		flag;

	index = 0;
	n_string = 0;
	flag = 0;
	while (s[index])
	{
		if (s[index] != c && flag == 0)
		{
			n_string++;
			flag++;
		}
		else if (s[index] == c)
			flag = 0;
		index++;
	}
	n_string++;
	string = (char **) malloc(n_string * sizeof(char *));
	return (string);
}

static void	s_split(const char *s, char c, int len_s, char **splitted_s)
{
	int		index_s;
	int		start;
	int		end;

	index_s = 0;
	start = 0;
	end = 0;
	while (index_s <= len_s)
	{
		if (s[index_s] != c && (s[start] == c || index_s == 0))
			start = index_s;
		if (s[index_s] == c || index_s == len_s)
			end = index_s;
		if (s[start] != c && (s[end] == c || end == len_s) && end > start)
		{
			*splitted_s = ft_substr(s, start, end - start);
			start = end;
			splitted_s++;
		}
		index_s++;
	}
	*splitted_s = NULL;
}

char	**ft_split(const char *s, char c)
{
	char	**splitted_s;
	int		len_s;

	splitted_s = alloc_s(s, c);
	len_s = (int) ft_strlen((char *)s);
	s_split(s, c, len_s, splitted_s);
	return (splitted_s);
}
