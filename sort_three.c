/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:46:00 by rkawahar          #+#    #+#             */
/*   Updated: 2024/05/20 14:34:22 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_third_pattern4(t_stack **lst)
{
	r(lst);
	s(lst);
	rr(lst);
	s(lst);
	r(lst);
	s(lst);
	r(lst);
	r(lst);
}

void	ft_third_pattern3(t_stack **lst, int num1, int num2, int num3)
{
	if (num2 < num3 && num3 < num1)
	{
		s(lst);
		r(lst);
		s(lst);
		r(lst);
		r(lst);
	}
	else if (num3 < num1 && num1 < num2)
	{
		r(lst);
		s(lst);
		rr(lst);
		s(lst);
		r(lst);
		r(lst);
		r(lst);
	}
	else
		ft_third_pattern4(lst);
}

void	ft_third_pattern2(t_stack **lst, int num1, int num2, int num3)
{
	if (num1 < num2 && num2 < num3)
	{
		r(lst);
		r(lst);
		r(lst);
	}
	else if (num1 < num3 && num3 < num2)
	{
		r(lst);
		s(lst);
		r(lst);
		r(lst);
	}
	else if (num2 < num1 && num1 < num3)
	{
		s(lst);
		r(lst);
		r(lst);
		r(lst);
	}
	else
		ft_third_pattern3(lst, num1, num2, num3);
}
