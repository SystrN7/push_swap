/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_sorter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalaup <fgalaup@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:15:44 by fgalaup           #+#    #+#             */
/*   Updated: 2021/05/12 16:15:28 by fgalaup          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"

void	sort_two(t_common_context *context)
{
	if (context->stack_a->next == NULL)
		return ;
	else if (context->stack_a->content > context->stack_a->next->content)
		intruction_add_exec(context, INSTRUCTION_SWAP_FIRST_A);
	return ;
}

void	sort_small_stack(t_common_context *cnt)
{
	int	i;

	i = 0;
	if (cnt->stack_a->content > cnt->stack_a->next->content
		&& (cnt->stack_a->next->content > cnt->stack_a->next->next->content
			|| cnt->stack_a->content < cnt->stack_a->next->next->content))
		intruction_add_exec(cnt, INSTRUCTION_SWAP_FIRST_A);
	while ((cnt->stack_a->content > cnt->stack_a->next->content
			|| cnt->stack_a->next->content > cnt->stack_a->next->next->content)
		&& i != 5)
	{
		intruction_add_exec(cnt, INSTRUCTION_REVERSE_ROTATE_A);
		cnt->stack_a = ft_blst_first(cnt->stack_a);
		if (cnt->stack_a->content > cnt->stack_a->next->content
			&& cnt->stack_a->next->content < cnt->stack_a->next->next->content)
		{
			intruction_add_exec(cnt, INSTRUCTION_SWAP_FIRST_A);
			return ;
		}
		i++;
	}
}

int	ft_get_min_pos(t_common_context *context)
{
	int						i;
	int						pos;
	int						min;
	t_bidirectional_list	*buff;

	buff = context->stack_a;
	i = 0;
	pos = 0;
	buff = ft_blst_first(context->stack_a);
	min = (int)buff->content;
	pos = 0;
	while (buff)
	{
		if ((int)buff->content < min)
		{
			min = (int)buff->content;
			pos = i;
		}
		buff = buff->next;
		i++;
	}
	return (pos);
}

void	sort_medium_stack_util(t_common_context *cnt, int pos)
{
	if ((unsigned long)pos < (cnt->stack_len / 2) +(cnt->stack_len % 2))
	{
		while (pos > 0)
		{
			intruction_add_exec(cnt, INSTRUCTION_ROTATE_A);
			pos--;
		}
		intruction_add_exec(cnt, INSTRUCTION_POP_A_PUSH_B);
	}
	else
	{
		while ((int)cnt->stack_len - ft_lstsize(
				(t_list *)cnt->stack_b) - pos > 0)
		{
			intruction_add_exec(cnt, INSTRUCTION_REVERSE_ROTATE_A);
			pos++;
		}
		intruction_add_exec(cnt, INSTRUCTION_POP_B_PUSH_A);
	}
}

void	sort_medium_stack(t_common_context *context)
{
	int	targets;

	targets = context->stack_len - 3;
	while (ft_lstsize((t_list *)context->stack_b) < targets)
	{
		sort_medium_stack_util(context, ft_get_min_pos(context));
		context->stack_b = ft_blst_first(context->stack_b);
		context->stack_a = ft_blst_first(context->stack_a);
	}
	sort_small_stack(context);
	context->stack_b = ft_blst_first(context->stack_b);
	while (ft_lstsize((t_list *)context->stack_b) > 0)
		intruction_add_exec(context, INSTRUCTION_POP_B_PUSH_A);
}
