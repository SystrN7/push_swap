/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalaup <fgalaup@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:04:02 by fgalaup           #+#    #+#             */
/*   Updated: 2021/05/10 11:46:02 by fgalaup          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common_instruction.h"

void	reverse_rotate_b(t_common_context *context)
{
	t_bidirectional_list	*link_to_move;

	link_to_move = ft_blst_last(context->stack_b);
	link_to_move->prev = NULL;
	context->stack_b = ft_blst_first(context->stack_b);
	context->stack_b->prev = link_to_move;
	link_to_move->next = context->stack_b;
}
