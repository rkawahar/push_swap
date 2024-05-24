/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 07:42:10 by rkawahar          #+#    #+#             */
/*   Updated: 2024/05/20 17:09:00 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	re_sort_second(t_stack **lst)
{
	int	num1;
	int	num2;

	*lst = (*lst)-> next;
	num1 = (*lst)-> num;
	*lst = (*lst)-> next;
	num2 = (*lst)-> num;
	if (num1 < num2)
		s(lst);
}

void	re_third_pattern(t_stack **lst, int num1, int num2, int num3)
{
	if (num1 < num3 && num3 < num2)
		r(lst);
	else if (num2 < num1 && num1 < num3)
		rr(lst);
	else if (num3 < num1 && num1 < num2)
		s(lst);
	else if (num2 < num3 && num3 < num1)
	{
		r(lst);
		s(lst);
		rr(lst);
	}
	else if (num1 < num2 && num2 < num3)
	{
		s(lst);
		rr(lst);
	}
}

void	re_sort_third(t_stack **lst)
{
	int	num1;
	int	num2;
	int	num3;

	ft_goto_nil(lst);
	*lst = (*lst)-> next;
	num1 = (*lst)-> num;
	*lst = (*lst)-> next;
	num2 = (*lst)-> num;
	*lst = (*lst)-> next;
	num3 = (*lst)-> num;
	ft_goto_nil(lst);
	re_third_pattern(lst, num1, num2, num3);
}

void	ft_reverse_under3(t_stack **lst)
{
	int	num;

	ft_goto_nil(lst);
	num = ft_lstlen(*lst);
	if (num == 2)
		re_sort_second(lst);
	else if (num == 3)
		re_sort_third(lst);
}

void	ft_sort_under6(t_stack **a, t_stack **b)
{
	int	i;
	int	min;

	min = ft_min(a);
	i = 0;
	while (i < 3)
	{
		ft_goto_nil(a);
		if ((*a)-> next -> num < min + 3)
		{
			p(b, a);
			i++;
		}
		else
			r(a);
	}
	ft_sort_under3(a);
	ft_reverse_under3(b);
	while (0 < i)
	{
		ft_goto_nil(b);
		p(a, b);
		i--;
	}
}
