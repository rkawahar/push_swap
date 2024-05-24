/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compression.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 03:59:17 by rkawahar          #+#    #+#             */
/*   Updated: 2024/05/15 04:11:03 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_numcpy(int *numbers, int ele_num)
{
	int	*ans;
	int	index;

	ans = (int *)malloc(sizeof(int) * ele_num);
	if (ans == NULL)
		return (NULL);
	index = 0;
	while (index < ele_num)
	{
		ans[index] = numbers[index];
		index++;
	}
	return (ans);
}

void	ft_swap_num(int *num1, int *num2)
{
	int	tmp;

	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

void	ft_bubble_sort(int *num, int ele_num)
{
	int	index;
	int	sorted;

	sorted = ele_num;
	while (ele_num != 1)
	{
		index = 0;
		while (index < ele_num - 1)
		{
			if (num[index] == num[index + 1])
				error_exit();
			else if (num[index] > num[index + 1])
				ft_swap_num(&num[index], &num[index + 1]);
			index++;
		}
		ele_num--;
	}
}

void	ft_convert_number(int *num, int *sorted_num, int ele_num)
{
	int	*converted_num;
	int	index;
	int	l;

	converted_num = (int *)malloc(sizeof(int) * ele_num);
	if (converted_num == NULL)
		error_exit();
	index = 0;
	while (index < ele_num)
	{
		l = 0;
		while (sorted_num[index] != num[l])
			l++;
		converted_num[l] = index;
		index++;
	}
	ft_create_lst(converted_num, ele_num);
}

void	ft_compression(int *numbers, int element)
{
	int	*sorted_num;

	sorted_num = ft_numcpy(numbers, element);
	if (sorted_num == NULL)
		error_exit();
	ft_bubble_sort(sorted_num, element);
	ft_convert_number(numbers, sorted_num, element);
}
