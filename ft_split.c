/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 01:31:51 by rkawahar          #+#    #+#             */
/*   Updated: 2024/05/20 12:50:39 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count(char *str)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '	')
			i++;
		if (str[i] == '-')
			i++;
		if (str[i] < '0' || '9' < str[i])
			error_exit();
		if (str[i + 1] == ' ' || str[i + 1] == '	' || str[i + 1] == '\0')
			cnt++;
		i++;
	}
	return (cnt);
}

void	ft_strlcpy(char *ans, char *str, int start, int end)
{
	int	i;

	i = 0;
	while (start < end)
		ans[i++] = str[start++];
	ans[i] = '\0';
}

void	ft_split_str(char *str, char **ans, int cnt)
{
	int		start;
	int		end;
	int		i;

	i = 1;
	end = 0;
	while (i <= cnt)
	{
		while (str[end] == ' ' || str[end] == '	')
			end++;
		start = end;
		if (str[end] == '-')
			end++;
		while ('0' <= str[end] && str[end] <= '9')
			end++;
		ans[i] = (char *)malloc(end - start + 1);
		if (ans[i] == NULL)
			error_exit();
		ft_strlcpy(ans[i], str, start, end);
		i++;
	}
}

char	**ft_split(char *str)
{
	char	**ans;
	int		cnt;
	int		i;

	cnt = ft_count(str);
	i = 0;
	ans = (char **)malloc(sizeof(char *) * (cnt + 2));
	if (ans == NULL)
		error_exit();
	ans[cnt + 1] = NULL;
	ans[0] = (char *)malloc(6);
	if (ans[0] == NULL)
		error_exit();
	ft_split_str(str, ans, cnt);
	return (ans);
}
