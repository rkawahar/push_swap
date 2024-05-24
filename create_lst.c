/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 04:13:10 by rkawahar          #+#    #+#             */
/*   Updated: 2024/05/15 17:14:13 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_lst(int number)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		error_exit();
	new -> num = number;
	new -> pre = NULL;
	new -> next = NULL;
	return (new);
}

t_stack	*ft_start_lst(int origin)
{
	t_stack	*s;

	s = (t_stack *)malloc(sizeof(t_stack));
	if (s == NULL)
		error_exit();
	s -> num = origin;
	s -> pre = s;
	s -> next = s;
	return (s);
}

void	ft_create_lst(int *num, int elenum)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*tmp;
	int		i;

	a = ft_start_lst(-1);
	b = ft_start_lst(-2);
	i = 0;
	while (i < elenum)
	{
		tmp = ft_new_lst(num[i]);
		ft_connect_end(&a, tmp);
		i++;
	}
	ft_judge_sort(&a, &b, elenum);
}
