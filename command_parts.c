/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 04:19:17 by rkawahar          #+#    #+#             */
/*   Updated: 2024/05/15 07:07:37 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_connect_end(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	tmp = (*lst)-> pre;
	(*lst)-> pre = new;
	new -> next = *lst;
	new -> pre = tmp;
	tmp -> next = new;
}

void	ft_connect_start(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	tmp = (*lst)-> next;
	(*lst)-> next = new;
	new -> pre = *lst;
	new -> next = tmp;
	tmp -> pre = new;
}

t_stack	*ft_remove_end(t_stack **lst)
{
	t_stack	*ans;
	t_stack	*tmp;

	ans = (*lst)-> pre;
	tmp = ans -> pre;
	ans -> next = NULL;
	ans -> pre = NULL;
	tmp -> next = *lst;
	(*lst)-> pre = tmp;
	return (ans);
}

t_stack	*ft_remove_start(t_stack **lst)
{
	t_stack	*ans;
	t_stack	*tmp;

	ans = (*lst)-> next;
	tmp = ans -> next;
	ans -> pre = NULL;
	ans -> next = NULL;
	tmp -> pre = *lst;
	(*lst)-> next = tmp;
	return (ans);
}
