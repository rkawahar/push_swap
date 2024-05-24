/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 06:01:23 by rkawahar          #+#    #+#             */
/*   Updated: 2024/05/20 17:08:55 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_stack **lst)
{
	int	tmp;

	*lst = (*lst)-> next;
	while ((*lst)->next -> num >= 0)
	{
		tmp = (*lst)-> num;
		*lst = (*lst)-> next;
		if ((*lst)-> num != tmp + 1)
			return (0);
	}
	ft_goto_nil(lst);
	return (1);
}

void	ft_judge_sort(t_stack **a, t_stack **b, int elenum)
{
	t_axis	*div;

	if (check_sort(a))
		exit(0);
	if (elenum <= 3)
		ft_sort_under3(a);
	else if (elenum <= 6)
		ft_sort_under6(a, b);
	else
	{
		div = ft_start_axis();
		div -> div1 = elenum / 3;
		div -> div2 = (elenum + (div -> div1)) / 2;
		ft_div3(a, b, div, elenum);
	}
	exit(0);
}
