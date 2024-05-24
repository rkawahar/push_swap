/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axis.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:31:23 by rkawahar          #+#    #+#             */
/*   Updated: 2024/05/20 10:01:27 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_axis	*ft_start_axis(void)
{
	t_axis	*origin;

	origin = (t_axis *)malloc(sizeof(t_axis));
	if (origin == NULL)
		error_exit();
	origin -> small = NULL;
	origin -> middle = NULL;
	origin -> large = NULL;
	origin -> min = 0;
	origin -> len = 0;
	origin -> div1 = 0;
	origin -> div2 = 0;
	origin -> pre = origin;
	return (origin);
}

void	ft_connect_axis(t_axis **axis)
{
	t_axis	*tmp1;
	t_axis	*tmp2;
	t_axis	*tmp3;

	tmp1 = ft_start_axis();
	tmp2 = ft_start_axis();
	tmp3 = ft_start_axis();
	(*axis)-> small = tmp1;
	(*axis)-> middle = tmp2;
	(*axis)-> large = tmp3;
	tmp2 -> pre = (*axis);
	tmp1 -> pre = (*axis);
	tmp3 -> pre = (*axis);
}
