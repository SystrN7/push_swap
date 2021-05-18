/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruiz <seruiz@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:04:02 by fgalaup           #+#    #+#             */
/*   Updated: 2021/05/18 10:28:15 by seruiz           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common_instruction.h"

void	reverse_rotate_b(t_common_context *context)
{
	t_bidirectional_list	*link_to_move;

	if (context->stack_b == NULL)
		return ;
	link_to_move = ft_blst_last(context->stack_b);
	context->stack_b = ft_blst_first(context->stack_b);
	if (link_to_move == context->stack_b)
		return ;
	link_to_move->prev->next = NULL;
	link_to_move->prev = NULL;
	link_to_move->next = context->stack_b;
	context->stack_b->prev = link_to_move;
}
