/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalaup <fgalaup@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:37:08 by fgalaup           #+#    #+#             */
/*   Updated: 2021/05/12 16:31:51 by fgalaup          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common_instruction.h"

void	rotate_b(t_common_context *context)
{
	t_bidirectional_list	*link_to_move;

	if (context->stack_b == NULL)
		return ;
	link_to_move = ft_blst_first(context->stack_b);
	context->stack_b = ft_blst_last(context->stack_b);
	if (link_to_move == context->stack_b)
		return ;
	link_to_move->next->prev = NULL;
	link_to_move->next = NULL;
	link_to_move->prev = context->stack_b;
	context->stack_b->next = link_to_move;
}
