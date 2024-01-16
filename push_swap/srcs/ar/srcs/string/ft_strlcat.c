/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:38:26 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/19 02:48:40 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	_dst_len;
	size_t	src_len;
	size_t	idx;

	idx = 0;
	dst_len = ft_strlen(dst);
	_dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	while (dst_len + 1 < size && src[idx])
	{
		dst[dst_len] = src[idx];
		dst_len++;
		idx++;
	}
	dst[dst_len] = '\0';
	if (dst_len <= size)
		return (src_len + _dst_len);
	else
		return (src_len + size);
}

// #include <string.h>
// #include <stdio.h>
// int main()
// {
// 	char dest[20] = "BlockDMask";
//     char src[20] = "Hell";
// 	printf("[intput]\n");
//     printf("ft_strlcat count: %zu\n", ft_strlcat(dest, src, 15));
// 	printf("dest :%s\n", dest);
// 	char dest_2[20] = "BlockDMask";
//     char src_2[20] = "Hell";
// 	printf("[ouput]\n");
//     printf("strlcat count: %lu\n", strlcat(dest_2, src_2, 15));
// 	printf("dest_2 :%s\n", dest_2);
//     printf("\n");
// }