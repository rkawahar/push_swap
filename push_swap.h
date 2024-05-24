/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 01:17:04 by rkawahar          #+#    #+#             */
/*   Updated: 2024/05/20 17:08:26 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>

typedef struct stack
{
	struct stack	*next;
	int				num;
	struct stack	*pre;
}					t_stack;

typedef struct axis
{
	struct axis	*small;
	struct axis	*middle;
	struct axis	*large;
	int			min;
	int			len;
	int			div1;
	int			div2;
	struct axis	*pre;
}					t_axis;

void	error_exit(void);
void	ft_split_str(char *str, char **ans, int cnt);
char	**ft_split(char *str);
void	ft_strlcpy(char *ans, char *str, int start, int end);
int		ft_count(char *str);
int		*ft_atoi_lst(char **str, int ele_num);
long	ft_atoi(char *str);
int		ft_charlst_len(char **str);
int		*ft_numcpy(int *numbers, int ele_num);
void	ft_swap_num(int *num1, int *num2);
void	ft_bubble_sort(int *num, int ele_num);
void	ft_convert_number(int *num, int *sorted_num, int ele_num);
void	ft_compression(int *numbers, int element);
void	ft_connect_end(t_stack **lst, t_stack *new);
t_stack	*ft_new_lst(int number);
t_stack	*ft_start_lst(int origin);
void	ft_create_lst(int *num, int elenum);
void	ft_connect_start(t_stack **lst, t_stack *new);
t_stack	*ft_remove_end(t_stack **lst);
t_stack	*ft_remove_start(t_stack **lst);
void	s(t_stack **s);
void	ss(t_stack **a, t_stack **b);
void	p(t_stack **add, t_stack **remove);
void	r(t_stack **s);
void	rr(t_stack **s);
void	rab(t_stack **lst1, t_stack **lst2);
void	rrab(t_stack **lst1, t_stack **lst2);
int		ft_lstlen(t_stack *s);
void	ft_third_pattern(t_stack **lst, int num1, int num2, int num3);
void	ft_sort_third(t_stack **lst);
void	ft_sort_second(t_stack **lst);
void	ft_sort_under3(t_stack **s);
void	ft_judge_sort(t_stack **a, t_stack **b, int elenum);
int		ft_min(t_stack **lst);
void	ft_sort_under6(t_stack **a, t_stack **b);
void	ft_reverse_under3(t_stack **lst);
void	re_sort_third(t_stack **lst);
void	re_sort_second(t_stack **lst);
void	re_third_pattern(t_stack **lst, int num1, int num2, int num3);
t_axis	*ft_start_axis(void);
void	ft_connect_axis(t_axis **axis);
void	ft_div3(t_stack **a, t_stack **b, t_axis *axis, int elenum);
void	ft_goto_nil(t_stack **s);
void	ft_third_pattern2(t_stack **lst, int num1, int num2, int num3);
void	ft_third_pattern3(t_stack **lst, int num1, int num2, int num3);
void	ft_third_pattern4(t_stack **lst);
void	ft_sort_num3(t_stack **lst);
void	ft_sort_num(t_stack **lst, int len);
void	ft_difine_div(t_axis *axis);
void	ft_over6_2(t_stack **a, t_stack **b, t_axis *axis, int elenum);
int		check_sort(t_stack **lst);

#endif