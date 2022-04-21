/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 21:08:56 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/04/21 15:59:43 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	len_str;
	char	*str;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	len_str = len_s1 + len_s2 + 1;
	str = (char *)malloc(len_str * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, len_s1 + 1);
	ft_strlcat(str, s2, len_str);
	return (str);
}
