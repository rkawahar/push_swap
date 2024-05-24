/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 04:36:07 by rkawahar          #+#    #+#             */
/*   Updated: 2024/05/17 19:22:58 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_stack **s)
{
	t_stack	*nord1;
	t_stack	*nord2;

	if ((*s)-> num == -1)
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
	nord1 = ft_remove_start(s);
	nord2 = ft_remove_start(s);
	ft_connect_start(s, nord1);
	ft_connect_start(s, nord2);
}

void	ss(t_stack **a, t_stack **b)
{
	t_stack	*nord1;
	t_stack	*nord2;

	nord1 = ft_remove_start(a);
	nord2 = ft_remove_start(a);
	ft_connect_start(a, nord1);
	ft_connect_start(a, nord2);
	nord1 = ft_remove_start(b);
	nord2 = ft_remove_start(b);
	ft_connect_start(b, nord1);
	ft_connect_start(b, nord2);
	write(1, "ss\n", 3);
}

void	p(t_stack **add, t_stack **remove)
{
	t_stack	*tmp;

	tmp = ft_remove_start(remove);
	ft_connect_start(add, tmp);
	if ((*add)-> num == -1)
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}

void	r(t_stack **s)
{
	t_stack	*tmp;

	if ((*s)-> num == -1)
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
	tmp = ft_remove_start(s);
	ft_connect_end(s, tmp);
}

void	rr(t_stack **s)
{
	t_stack	*tmp;

	if ((*s)-> num == -1)
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
	tmp = ft_remove_end(s);
	ft_connect_start(s, tmp);
}
