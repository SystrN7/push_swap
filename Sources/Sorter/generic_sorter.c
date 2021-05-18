/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_sorter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruiz <seruiz@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 12:17:33 by seruiz            #+#    #+#             */
/*   Updated: 2021/05/18 10:27:30 by seruiz           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"

int	ft_get_num_pos(t_bidirectional_list	*stack, int	min, int max)
{
	int						i;
	int						pos_top;
	int						pos_bot;
	t_bidirectional_list	*buff;

	buff = stack;
	i = 0;
	pos_top = -1;
	buff = ft_blst_first(stack);
	while (buff)
	{
		if ((int)buff->content >= min && (int)buff->content <= max)
		{
			if (pos_top == -1)
				pos_top = i;
			pos_bot = i;
		}
		buff = buff->next;
		i++;
	}
	if (pos_top == -1)
		return (-2147483648);
	if (pos_top < i - pos_bot)
		return (pos_top);
	return (pos_bot);
}

void	extract_chunk(t_common_context *context, int min, int max)
{
	int	pos;
	int	len;

	pos = ft_get_num_pos(context->stack_a, min, max);
	len = ft_lstsize((t_list *)context->stack_a);
	while (pos != -2147483648 && context->stack_a)
	{
		if (pos < (len / 2) + (len % 2))
		{
			while (pos > 0 && pos--)
				intruction_add_exec(context, INSTRUCTION_ROTATE_A);
			intruction_add_exec(context, INSTRUCTION_POP_A_PUSH_B);
		}
		else
		{
			while (context->stack_len - ft_lstsize(
					(t_list *)context->stack_b) - pos > 0 && ++pos)
				intruction_add_exec(context, INSTRUCTION_REVERSE_ROTATE_A);
			intruction_add_exec(context, INSTRUCTION_POP_A_PUSH_B);
		}
		pos = ft_get_num_pos(context->stack_a, min, max);
		len = ft_lstsize((t_list *)context->stack_a);
	}
}

int	ft_get_max_pos(t_bidirectional_list *stack)
{
	int						pos;
	int						max_hold;
	int						i;
	t_bidirectional_list	*buff;

	buff = ft_blst_first(stack);
	i = 0;
	pos = 0;
	max_hold = 0;
	while (buff)
	{
		if ((int)buff->content >= max_hold)
		{
			max_hold = (int)buff->content;
			pos = i;
		}
		i++;
		buff = buff->next;
	}
	return (pos);
}

void	repush_stack(t_common_context *context)
{
	int	pos;
	int	len;

	pos = ft_get_max_pos(context->stack_b);
	len = ft_lstsize((t_list *)context->stack_b);
	while (context->stack_b)
	{
		if (pos < (len / 2) + (len % 2))
		{
			while (pos > 0 && pos--)
				intruction_add_exec(context, INSTRUCTION_ROTATE_B);
			intruction_add_exec(context, INSTRUCTION_POP_B_PUSH_A);
		}
		else
		{
			while (pos < len)
			{
				intruction_add_exec(context, INSTRUCTION_REVERSE_ROTATE_B);
				pos++;
			}
			intruction_add_exec(context, INSTRUCTION_POP_B_PUSH_A);
		}
		pos = ft_get_max_pos(context->stack_b);
		len = ft_lstsize((t_list *)context->stack_b);
	}
}

void	generic_sorter(t_common_context *context)
{
	int	chunks;
	int	chunk_size;
	int	min;
	int	max;

	if (context->stack_len > 200)
		chunks = 11;
	else if (context->stack_len > 500)
		chunks = 22;
	else
		chunks = 5;
	chunk_size = context->stack_len / chunks;
	min = 0;
	max = chunk_size - 1;
	while ((unsigned int)max < context->stack_len)
	{
		extract_chunk(context, min, max);
		min = min + chunk_size;
		max = max + chunk_size;
	}
	while (context->stack_a)
		intruction_add_exec(context, INSTRUCTION_POP_A_PUSH_B);
	repush_stack(context);
}
