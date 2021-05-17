/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_show.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalaup <fgalaup@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:53:51 by fgalaup           #+#    #+#             */
/*   Updated: 2021/05/12 15:54:11 by fgalaup          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common_stack.h"

void	ft_blst_show(t_bidirectional_list	*stack)
{
	stack = ft_blst_first(stack);
	while (stack)
	{
		printf(" %d ", (int)stack->content);
		stack = stack->next;
	}
	printf("\n");
}
