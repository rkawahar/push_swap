/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 01:26:48 by rkawahar          #+#    #+#             */
/*   Updated: 2024/05/20 15:21:41 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int	ft_lstlen(t_stack *s)
{
	int	ans;

	ans = 0;
	s = s -> next;
	while (s -> num >= 0)
	{
		ans++;
		s = s -> next;
	}
	return (ans);
}

int	ft_min(t_stack **lst)
{
	int	ans;

	ans = INT_MAX;
	ft_goto_nil(lst);
	*lst = (*lst)-> next;
	while ((*lst)-> num >= 0)
	{
		if ((*lst)-> num < ans)
			ans = (*lst)-> num;
		*lst = (*lst)-> next;
	}
	return (ans);
}

void	ft_goto_nil(t_stack **s)
{
	while ((*s)-> num >= 0)
		*s = (*s)-> next;
}
