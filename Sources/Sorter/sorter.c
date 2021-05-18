/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalaup <fgalaup@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:47:56 by fgalaup           #+#    #+#             */
/*   Updated: 2021/05/18 12:16:02 by fgalaup          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"

void	sorter_shutdown(t_common_context *context)
{
	int	status;

	status = context->status;
	ft_managed_free(context);
	ft_managed_free_all();
	exit(status);
}

void	sorter_init(t_common_context *context, char const *argv[])
{
	ft_managed_termination_function((t_ftermination) sorter_shutdown);
	ft_managed_termination_params(context);
	context->stack_a = stack_create(argv);
	context->stack_b = NULL;
	stack_create_continuous_list(context);
}

void	sorter_start(char const *argv[])
{
	t_common_context	*context;

	context = ft_managed_malloc(sizeof(t_common_context));
	ft_memset(context, 0, sizeof(t_common_context));
	sorter_init(context, argv);
	context->stack_a = ft_blst_first(context->stack_a);
	context->stack_len = ft_lstsize((t_list *)context->stack_a);
	if (context->stack_len <= 1)
		sorter_shutdown(context);
	else if (context->stack_len <= 2)
		sort_two(context);
	else if (context->stack_len <= 3)
		sort_small_stack(context);
	else if (context->stack_len <= 20)
		sort_medium_stack(context);
	else
		generic_sorter(context);
	intruction_show_list(context);
	sorter_shutdown(context);
}

int	main(int argc, char const *argv[])
{
	char	**args;
	int		i;

	if (argc <= 1)
		return (0);
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = (char **)argv + 1;
	sorter_start((const char **)args);
	if (argc == 2)
	{
		i = 0;
		while (args[i])
			ft_managed_free(args[i++]);
		ft_managed_free(args);
	}
	return (0);
}
