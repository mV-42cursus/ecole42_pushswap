/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:06:58 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/19 02:48:43 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = 0;
	while ((len + 1 < size) && src[len])
	{
		dst[len] = src[len];
		len++;
	}
	if (size != 0)
		dst[len] = '\0';
	while (src[len])
		len++;
	return (len);
}
