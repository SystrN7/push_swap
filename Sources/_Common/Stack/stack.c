/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalaup <fgalaup@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:51:42 by fgalaup           #+#    #+#             */
/*   Updated: 2021/05/11 16:06:49 by fgalaup          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common_stack.h"
#include <limits.h>

t_blst	stack_create(char const *argv[])
{
	t_bidirectional_list	*stack;
	size_t					i;
	long long				number;
	size_t					number_size;

	i = 0;
	stack = NULL;
	while (argv[i])
	{
		number_size = ft_strtoll(argv[i], &number);
		if ((argv[i][0] == '\0') || number_size != ft_strlen(argv[i]))
			error_fatal(ERROR_ARG_NOT_NUMBER, argv[i]);
		if (number_size > 10 || number > INT_MAX || number < INT_MIN)
			error_fatal(ERROR_ARG_INT_BIGGER, argv[i]);
		if (stack_double_exist(stack, (void *)number))
			error_fatal(ERROR_ARG_NUMBER_ALREADY_EXISTS, argv[i]);
		ft_blst_new_back(&stack, (void *)number, NULL);
		i++;
	}
	return (stack);
}

t_bool	stack_double_exist(t_bidirectional_list *stack, void *number)
{
	t_bidirectional_list	*it;

	it = stack;
	while (it)
	{
		if (it->content == number)
			return (FT_TRUE);
		it = it->prev;
	}
	return (FT_FALSE);
}
