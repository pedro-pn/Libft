/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:11:23 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/04/12 04:34:13 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

ssize_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		counter;
	size_t	length_dst;
	size_t	length_src;
	int		counter2;

	counter = 0;
	length_dst = 0;
	length_src = 0;
	while (dst[length_dst])
		length_dst++;
	while (src[length_src])
		length_src++;
	counter2 = length_dst;
	while ((counter2 < (int) size - 1 || (int) size < 0) && src[counter])
	{
		dst[counter2] = src[counter];
		counter++;
		counter2++;
	}
	if (size > 0)
		dst[counter2] = '\0';
	if (size < length_dst)
		return (size + length_src);
	return (length_dst + length_src);
}
