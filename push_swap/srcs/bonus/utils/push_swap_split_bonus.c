/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_split_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:32:18 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/21 03:21:14 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	**ft_split_ps_bonus(char **av, char c)
{
	size_t		word_cnt;
	size_t		word_len;
	size_t		rotation;
	char		**res;

	word_cnt = ft_count_words_ps_bonus(av, c);
	res = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	if (!res)
		return (NULL);
	rotation = -1;
	while (++rotation < word_cnt)
	{
		while (*av[1] == c || *av[1] == '\0')
			av[1]++;
		word_len = ft_count_wordlen_ps_bonus(av[1], c);
		res[rotation] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (res[rotation] == NULL)
			return (ft_memory_manager_ps_bonus(res, rotation));
		ft_word_cpy_ps_bonus(&res, av[1], word_len, rotation);
		av[1] = av[1] + word_len;
	}
	res[rotation] = NULL;
	return (res);
}

size_t	ft_count_words_ps_bonus(char **av, char c)
{
	size_t	cnt;
	size_t	_i;
	size_t	i;

	cnt = 0;
	_i = 0;
	i = 0;
	while (av[++_i])
	{
		i = 0;
		while (av[_i][i])
		{
			if (av[_i][i] != c && (av[_i][i + 1] == c || av[_i][i + 1] == '\0'))
				cnt++;
			i++;
		}
	}
	return (cnt);
}

size_t	ft_count_wordlen_ps_bonus(char *s, char c)
{
	size_t	i;

	i = 0;
	while (!(s[i] == c || s[i] == '\0'))
		i++;
	return (i);
}

char	**ft_memory_manager_ps_bonus(char **res, size_t rotation)
{
	while (rotation > 0)
	{
		rotation--;
		free(res[rotation]);
	}
	free(res);
	return (NULL);
}

void	ft_word_cpy_ps_bonus(char ***res, char *s, size_t word_len,
					size_t rotation)
{
	size_t	i;

	i = 0;
	while (i < word_len)
	{
		res[0][rotation][i] = s[i];
		i++;
	}
	res[0][rotation][i] = '\0';
}
