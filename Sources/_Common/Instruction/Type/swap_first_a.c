/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_first_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalaup <fgalaup@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:31:36 by fgalaup           #+#    #+#             */
/*   Updated: 2021/05/07 15:34:20 by fgalaup          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common_stack.h"

void	swap_first_a(t_common_context *context)
{
	context->stack_a = ft_blst_first(context->stack_a);
	ft_blst_swap(context->stack_a, context->stack_a->next);
}
