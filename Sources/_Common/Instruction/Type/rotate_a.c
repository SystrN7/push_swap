/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalaup <fgalaup@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:04:02 by fgalaup           #+#    #+#             */
/*   Updated: 2021/05/12 16:31:51 by fgalaup          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common_instruction.h"

void	rotate_a(t_common_context *context)
{
	t_bidirectional_list	*link_to_move;

	if (context->stack_a == NULL)
		return ;
	link_to_move = ft_blst_first(context->stack_a);
	context->stack_a = ft_blst_last(context->stack_a);
	if (link_to_move == context->stack_a)
		return ;
	link_to_move->next->prev = NULL;
	link_to_move->next = NULL;
	link_to_move->prev = context->stack_a;
	context->stack_a->next = link_to_move;
}
