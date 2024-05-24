/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 01:09:03 by rkawahar          #+#    #+#             */
/*   Updated: 2024/05/20 12:54:05 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_charlst_len(char **str)
{
	int	ans;

	ans = 0;
	while (str[ans] != NULL)
		ans++;
	return (ans);
}

long	ft_atoi(char *str)
{
	int		index;
	long	ans;
	int		neg_flg;

	index = 0;
	ans = 0;
	neg_flg = 1;
	while (str[index])
	{
		if (str[index] == '-' && neg_flg == 1)
			neg_flg = -1;
		else if ('0' <= str[index] && str[index] <= '9')
		{
			ans = ans * 10 + (str[index] - '0');
			if (ans * neg_flg < INT_MIN || INT_MAX < ans * neg_flg)
				error_exit();
		}
		else
			error_exit();
		index++;
	}
	ans *= neg_flg;
	return (ans);
}

int	*ft_atoi_lst(char **str, int ele_num)
{
	int	*numbers;
	int	index;
	int	str_i;
	int	tmp;

	numbers = (int *)malloc(sizeof(int) * ele_num);
	if (numbers == NULL)
		error_exit();
	index = 0;
	str_i = 1;
	while (index < ele_num)
	{
		tmp = ft_atoi(str[str_i++]);
		numbers[index] = tmp;
		index++;
	}
	return (numbers);
}

int	main(int argc, char **argv)
{
	int	*numbers;

	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		argv = ft_split(argv[1]);
		argc = ft_charlst_len(argv);
	}
	numbers = ft_atoi_lst(argv, argc - 1);
	if (argc == 2)
		exit(1);
	ft_compression(numbers, argc - 1);
}
