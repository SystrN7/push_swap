/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_sorter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruiz <seruiz@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 12:17:33 by seruiz            #+#    #+#             */
/*   Updated: 2021/05/12 12:54:59 by seruiz           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"

int		ft_get_num_pos(t_common_context *context, int	min, int max)
{
	int						i;
	int						pos_top;
	int						pos_bot;
	t_bidirectional_list	*buff;

	buff = context->stack_a;
	i = 0;
	pos_top = -1;
	buff = ft_blst_first(context->stack_a);
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
	if ((unsigned int)pos_top < context->stack_len - pos_bot)
		return (pos_top);
	return (pos_bot);
}


void	generic_sorter(t_common_context *context)
{
	int	chunks;
	int	chunk_size;
	int	pos;

	if (context->stack_len > 200)
		chunks = 11;
	else
		chunks = 5;
	chunk_size = context->stack_len / chunks;
	pos = ft_get_num_pos(context, 0, 19);
	printf("chunk size = %d\n", chunk_size);
	while (pos != -1)
	{
		if ((unsigned long)pos < (context->stack_len / 2) + (context->stack_len % 2))
		{
			while (pos > 0)
			{
				intruction_add_exec(context, INSTRUCTION_ROTATE_A);
				pos--;
			}
			ft_blst_show(context->stack_a);
			intruction_add_exec(context, INSTRUCTION_POP_A_PUSH_B);
			ft_blst_show(context->stack_a);
		}
		else
		{
			while ((int)context->stack_len - ft_lstsize((t_list *)context->stack_b) - pos > 0)
			{
				intruction_add_exec(context, INSTRUCTION_REVERSE_ROTATE_A);
				pos++;
			}
			intruction_add_exec(context, INSTRUCTION_POP_B_PUSH_A);
		}
		pos = ft_get_num_pos(context, 0, 19);
		printf("pos = %d\n", pos);
	}
}
