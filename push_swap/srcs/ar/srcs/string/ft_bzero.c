/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:10:19 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/19 02:48:21 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n--)
	{
		*ptr++ = '\0';
	}
}
// #include <string.h>
// #include <stdio.h>
// int main(void)
// {
//     char str[50];
//     printf("---------------[original bzero]----------------------\n");
//     strcpy(str,"This is string.h library function");
//     puts(str);
//     bzero(str, 50);
//     puts(str);
//     printf("---------------[42:ft_bzero]----------------------\n");
//     strcpy(str,"This is string.h library function");
//     ft_bzero(str, 50);
//     puts(str);
//     return(0);
// }
