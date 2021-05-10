/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalaup <fgalaup@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:38:42 by fgalaup           #+#    #+#             */
/*   Updated: 2021/05/10 13:49:47 by fgalaup          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char const *argv[])
{
	if (argc <= 1)
		return (0);
	checker_start(argv);
	return (0);
}

void	checker_init(t_common_context *context, char const *argv[])
{
	ft_managed_termination_function((t_ftermination) checker_shutdown);
	ft_managed_termination_params(context);
	context->stack_a = stack_create(argv + 1);
	context->stack_b = NULL;
	
	// context->sort_instructions = ;
}

void	checker_start(char const *argv[])
{
	t_common_context	*context;

	context = ft_managed_malloc(sizeof(t_common_context));
	ft_memset(&context, 0, sizeof(t_common_context));
	checker_init(context, argv);
	intruction_exec(context);
	if (stack_is_sort(context->stack_a) && context->stack_b == NULL)
		ft_putstr_fd(standard_output, "OK\n");
	else
		ft_putstr_fd(standard_output, "KO\n");
	checker_shutdown(context);
}

void	checker_shutdown(t_common_context *context)
{
	int	status;

	status = context->status;
	ft_managed_free(context);
	ft_managed_free_all();
	exit(status);
}
