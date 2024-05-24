/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 05:57:21 by rkawahar          #+#    #+#             */
/*   Updated: 2024/05/15 07:07:14 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rab(t_stack **lst1, t_stack **lst2)
{
	t_stack	*nord;

	nord = ft_remove_start(lst1);
	ft_connect_end(lst1, nord);
	nord = ft_remove_start(lst2);
	ft_connect_end(lst2, nord);
	write(1, "rr\n", 3);
}

void	rrab(t_stack **lst1, t_stack **lst2)
{
	t_stack	*nord;

	nord = ft_remove_end(lst1);
	ft_connect_start(lst1, nord);
	nord = ft_remove_end(lst2);
	ft_connect_start(lst2, nord);
	write(1, "rrr\n", 4);
}
