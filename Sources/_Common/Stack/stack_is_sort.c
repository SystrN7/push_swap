/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalaup <fgalaup@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:58:12 by fgalaup           #+#    #+#             */
/*   Updated: 2021/05/11 14:26:54 by fgalaup          ###   ########lyon.fr   */
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
			if ((long long)it->content > (long long)it->next->content)
				return (FT_FALSE);
		it = it->next;
	}
	return (FT_TRUE);
}
