/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalaup <fgalaup@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:58:12 by fgalaup           #+#    #+#             */
/*   Updated: 2021/05/10 10:24:04 by fgalaup          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common_stack.h"

t_bool	stack_is_sort(t_bidirectional_list *stack)
{
	t_bidirectional_list	*it;

	it = stack;
	while (it != NULL)
	{
		if (it->next != NULL)
			if (it->content > it->next->content)
				return (FT_FALSE);
		it->next;
	}
	return (FT_TRUE);
}
