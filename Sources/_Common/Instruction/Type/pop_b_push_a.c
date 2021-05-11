/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_b_push_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruiz <seruiz@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:49:24 by fgalaup           #+#    #+#             */
/*   Updated: 2021/05/10 16:27:02 by seruiz           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common_instruction.h"

void	pop_b_push_a(t_common_context *context)
{
	context->stack_a = ft_blst_first(context->stack_a);
	context->stack_b = ft_blst_first(context->stack_b);
	ft_blst_move_before(&context->stack_b, &context->stack_a);
	write(1, "pa\n", 3);
}
