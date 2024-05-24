/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_over6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:59:23 by rkawahar          #+#    #+#             */
/*   Updated: 2024/05/20 14:34:03 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_num3(t_stack **lst)
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
	ft_third_pattern2(lst, num1, num2, num3);
}

void	ft_sort_num(t_stack **lst, int len)
{
	if (len == 3)
		ft_sort_num3(lst);
	else if (len == 2)
	{
		ft_goto_nil(lst);
		ft_sort_second(lst);
		r(lst);
		r(lst);
	}
	else
		r(lst);
}

void	ft_difine_div(t_axis *axis)
{
	int	tmp;

	axis -> small -> min = axis -> min;
	axis -> small -> div1 = (axis -> div1 - axis -> min) / 3 + axis -> min;
	axis -> small -> div2 = (axis -> div1 + axis -> small -> div1) / 2;
	axis -> middle -> min = axis -> div1;
	axis -> middle -> div1 = (axis -> div2 - axis -> div1) / 3 + axis -> div1;
	axis -> middle -> div2 = (axis -> middle -> div1 + axis -> div2) / 2;
	axis -> large -> min = axis -> div2;
	tmp = axis -> len + axis -> min;
	axis -> large -> div1 = (tmp - axis -> div2) / 3 + axis -> div2;
	axis -> large -> div2 = (tmp + axis -> large -> div1) / 2;
	axis -> small -> len = axis -> div1 - axis -> min;
	axis -> middle -> len = axis -> div2 - axis -> div1;
	axis -> large -> len = tmp - axis -> div2;
}

void	ft_over6_2(t_stack **a, t_stack **b, t_axis *axis, int elenum)
{
	int	i;
	int	move;

	i = -1;
	move = 0;
	while (++i < elenum)
	{
		if ((*a)-> next -> num < axis -> div2)
		{
			p(b, a);
			move++;
			if ((*b)-> next -> num < axis -> div1)
				r(b);
		}
		else
			r(a);
		ft_goto_nil(a);
		ft_goto_nil(b);
	}
	while (move < i--)
		rr(a);
	while (0 < move--)
		p(a, b);
}

void	ft_div3(t_stack **a, t_stack **b, t_axis *axis, int elenum)
{
	if (elenum > 3)
	{
		ft_goto_nil(a);
		ft_connect_axis(&axis);
		axis -> len = elenum;
		ft_difine_div(axis);
		ft_over6_2(a, b, axis, elenum);
		ft_div3(a, b, axis -> small, axis -> small -> len);
		ft_div3(a, b, axis -> middle, axis -> middle -> len);
		ft_div3(a, b, axis -> large, axis -> large -> len);
	}
	else
	{
		ft_goto_nil(a);
		ft_sort_num(a, elenum);
	}
}
