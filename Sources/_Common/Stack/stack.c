/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalaup <fgalaup@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:51:42 by fgalaup           #+#    #+#             */
/*   Updated: 2021/05/12 13:02:57 by fgalaup          ###   ########lyon.fr   */
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

static int	number_of_inferior_value(t_bidirectional_list *it, long long number)
{
	int	continuous_number;

	continuous_number = 0;
	while (it)
	{
		if (number > (long long)it->content)
			continuous_number++;
		it = it->next;
	}
	return (continuous_number);
}

void	stack_create_continuous_list(t_common_context *context)
{
	t_bidirectional_list	*it_origin;
	t_bidirectional_list	*it_continuous;
	long long				continuous_number;

	context->stack_a = ft_blst_first(context->stack_a);
	it_origin = context->stack_a;
	it_continuous = NULL;
	while (it_origin)
	{
		continuous_number = number_of_inferior_value(
				context->stack_a,
				(long long)it_origin->content
				);
		it_origin = it_origin->next;
		ft_blst_new_back(
			&it_continuous,
			(void *)continuous_number,
			NULL);
	}
	ft_blst_clear(&it_origin, NULL);
	context->stack_a = it_continuous;
}
