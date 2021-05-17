/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_a_push_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalaup <fgalaup@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:53:12 by fgalaup           #+#    #+#             */
/*   Updated: 2021/05/12 16:31:55 by fgalaup          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common_instruction.h"

void	pop_a_push_b(t_common_context *context)
{
	context->stack_a = ft_blst_first(context->stack_a);
	context->stack_b = ft_blst_first(context->stack_b);
	ft_blst_move_before(&context->stack_a, &context->stack_b);
}
