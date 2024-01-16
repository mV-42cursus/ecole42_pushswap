/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:04:06 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/19 02:46:48 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	dfs(int nb, int fd)
{
	int	rem;

	rem = 0;
	if (nb < 10)
	{
		rem = nb + '0';
		write(fd, &rem, 1);
	}
	else
	{
		rem = (nb % 10) + '0';
		dfs(nb / 10, fd);
		write(fd, &rem, 1);
	}
}

static void	ft_putnbr(int nb, int fd)
{
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = nb * (-1);
	}
	dfs(nb, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	ft_putnbr(n, fd);
}

// #include <stdio.h>
// int main()
// {
// 	ft_putnbr_fd(-2147483648, 0); printf("\n");
// 	ft_putnbr_fd(-2147483648, 1); printf("\n");
// 	ft_putnbr_fd(-2147483648, 2); printf("\n");
// 	ft_putnbr_fd(0, 0); printf("\n");
// 	ft_putnbr_fd(0, 1); printf("\n");
// 	ft_putnbr_fd(0, 2); printf("\n");
// 	ft_putnbr_fd(2147483647, 0); printf("\n");
// 	ft_putnbr_fd(2147483647, 1); printf("\n");
// 	ft_putnbr_fd(2147483647, 2); printf("\n");
// }