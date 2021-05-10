/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_first_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalaup <fgalaup@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:31:36 by fgalaup           #+#    #+#             */
/*   Updated: 2021/05/07 15:34:49 by fgalaup          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common_stack.h"

void	swap_first_b(t_common_context *context)
{
	context->stack_b = ft_blst_first(context->stack_b);
	ft_blst_swap(context->stack_b, context->stack_b->next);
}
