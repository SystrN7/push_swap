/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalaup <fgalaup@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:47:56 by fgalaup           #+#    #+#             */
/*   Updated: 2021/05/12 11:21:36 by fgalaup          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"

int	main(int argc, char const *argv[])
{
	if (argc <= 1)
		return (0);
	sorter_start(argv);
	return (0);
}

void	sorter_init(t_common_context *context, char const *argv[])
{
	ft_managed_termination_function((t_ftermination) sorter_shutdown);
	ft_managed_termination_params(context);
	context->stack_a = stack_create(argv + 1);
	context->stack_b = NULL;
}

void	sorter_start(char const *argv[])
{
	t_common_context	*context;

	context = ft_managed_malloc(sizeof(t_common_context));
	ft_memset(context, 0, sizeof(t_common_context));
	sorter_init(context, argv);

	intruction_show_list(context);
	sorter_shutdown(context);
}

void	sorter_shutdown(t_common_context *context)
{
	int	status;

	status = context->status;
	ft_managed_free(context);
	ft_managed_free_all();
	exit(status);
}
