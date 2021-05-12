/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_sorter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruiz <seruiz@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 12:17:33 by seruiz            #+#    #+#             */
/*   Updated: 2021/05/12 15:11:29 by seruiz           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"

int		ft_get_num_pos(t_bidirectional_list	*stack, int	min, int max)
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

	pos = ft_get_num_pos(context->stack_a, min, max);
	//printf("pos = %d\nmin = %d\nmax = %d\n", pos, min, max);
	while (pos != -2147483648 && context->stack_a)
	{
		if ((unsigned long)pos < (context->stack_len / 2) + (context->stack_len % 2))
		{
			while (pos > 0)
			{
				intruction_add_exec(context, INSTRUCTION_ROTATE_A);
				pos--;
			}
			//ft_blst_show(context->stack_a);
			intruction_add_exec(context, INSTRUCTION_POP_A_PUSH_B);
			//ft_blst_show(context->stack_a);
		}
		else
		{
			while ((int)context->stack_len - ft_lstsize((t_list *)context->stack_b) - pos > 0)
			{
				intruction_add_exec(context, INSTRUCTION_REVERSE_ROTATE_A);
				pos++;
			}
			intruction_add_exec(context, INSTRUCTION_POP_A_PUSH_B);
		}
		pos = ft_get_num_pos(context->stack_a, min, max);
		//printf("pos = %d\n", pos);
	}
}

void	repush_chunk(t_common_context *context, int	min, int max)
{
	int						actual;
	int						i;
	int						pos;
	t_bidirectional_list	*buff;

	buff = context->stack_a;
	i = 0;
	actual = max;
	while (buff)
	{
		pos = ft_get_num_pos(context->stack_b, min, max);
		buff = buff->next;
	}
}

void	generic_sorter(t_common_context *context)
{
	int	chunks;
	int	chunk_size;
	int	min;
	int	max;

	if (context->stack_len > 200)
		chunks = 10;
	else
		chunks = 5;
	chunk_size = context->stack_len / chunks;
	//printf("chunk size = %d\n", chunk_size);
	min = 0;
	max = chunk_size - 1;
	while ((unsigned int)max < context->stack_len)
	{
		printf("min = %d\nmax = %d\n", min, max);
		extract_chunk(context, min, max);
		min = min + chunk_size;
		max = max + chunk_size;
	}
}
