/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_b_push_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalaup <fgalaup@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:49:24 by fgalaup           #+#    #+#             */
/*   Updated: 2021/05/07 15:36:41 by fgalaup          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common_stack.h"

void	pop_b_push_a(t_common_context *context)
{
	context->stack_a = ft_blst_first(context->stack_a);
	context->stack_b = ft_blst_first(context->stack_b);
	ft_blst_move_before(&context->stack_b, &context->stack_a);
}