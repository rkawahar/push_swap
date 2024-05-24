/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 06:06:03 by rkawahar          #+#    #+#             */
/*   Updated: 2024/05/20 15:05:37 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_third_pattern(t_stack **lst, int num1, int num2, int num3)
{
	if (num1 < num3 && num3 < num2)
	{
		r(lst);
		s(lst);
		rr(lst);
	}
	else if (num2 < num1 && num1 < num3)
		s(lst);
	else if (num3 < num1 && num1 < num2)
		rr(lst);
	else if (num3 < num2 && num2 < num1)
	{
		s(lst);
		rr(lst);
	}
	else if (num2 < num3 && num3 < num1)
		r(lst);
}

void	ft_sort_third(t_stack **lst)
{
	int	num1;
	int	num2;
	int	num3;

	*lst = (*lst)-> next;
	num1 = (*lst)-> num;
	*lst = (*lst)-> next;
	num2 = (*lst)-> num;
	*lst = (*lst)-> next;
	num3 = (*lst)-> num;
	ft_goto_nil(lst);
	ft_third_pattern(lst, num1, num2, num3);
}

void	ft_sort_second(t_stack **lst)
{
	int	num1;
	int	num2;

	*lst = (*lst)-> next;
	num1 = (*lst)-> num;
	*lst = (*lst)-> next;
	num2 = (*lst)-> num;
	ft_goto_nil(lst);
	if (num1 > num2)
		s(lst);
}

void	ft_sort_under3(t_stack **s)
{
	int	num;

	ft_goto_nil(s);
	num = ft_lstlen(*s);
	if (num == 2)
		ft_sort_second(s);
	else if (num == 3)
		ft_sort_third(s);
}
