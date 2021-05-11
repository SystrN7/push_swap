/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruiz <seruiz@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:47:56 by fgalaup           #+#    #+#             */
/*   Updated: 2021/05/11 14:31:09 by seruiz           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"

void	ft_blst_show(t_bidirectional_list	*stack)
{
	stack = ft_blst_first(stack);
	while (stack)
	{
		printf("stack->content = %d ", (int)stack->content);
		stack = stack->next;
	}
	printf("\n");
}

void	sort_two(t_common_context *context)
{
	if (context->stack_a->next == NULL)
		return ;
	else if (context->stack_a->content > context->stack_a->next->content)
		swap_first_a(context);
	return ;
}

void	sort_small_stack(t_common_context *context)
{
	int	i;

	i = 0;
	if (context->stack_a->content > context->stack_a->next->content
			&& (context->stack_a->next->content > context->stack_a->next->next->content || context->stack_a->content < context->stack_a->next->next->content))
		swap_first_a(context);
		while ((context->stack_a->content > context->stack_a->next->content
				|| context->stack_a->next->content > context->stack_a->next->next->content) && i != 5)
			{
				reverse_rotate_a(context);
				context->stack_a = ft_blst_first(context->stack_a);
				if (context->stack_a->content > context->stack_a->next->content
					&& context->stack_a->next->content < context->stack_a->next->next->content)
					{
						swap_first_a(context);
						return ;
					}
				i++;
			}
}

void	sort_medium_stack(t_common_context *context)
{
	int	targets;
	int	pos;
	int	min;
	int	i;
	t_bidirectional_list	*buff;

	pos = 0;
	i = 0;
	targets = context->stack_len - 3;
	buff = context->stack_a;
	min = (int)buff->content;
	while (ft_lstsize((t_list *)context->stack_b) < targets)
	{
		buff = ft_blst_first(context->stack_a);
		min = (int)buff->content;
		pos = 0;
		while (buff)
		{
			if ((int)buff->content < min)
			{
				min = (int)buff->content;
				pos = i;
			}
			buff = buff->next;
			i++;
		}
		i = 0;
		if ((unsigned long)pos < (context->stack_len / 2) + (context->stack_len % 2))
		{
			while (pos > 0)
			{
				rotate_a(context);
				pos--;
			}
			pop_a_push_b(context);
		}
		else
		{
			while ((int)context->stack_len - ft_lstsize((t_list *)context->stack_b) - pos > 0)
			{
				reverse_rotate_a(context);
				pos++;
			}
			pop_a_push_b(context);
		}
		context->stack_b = ft_blst_first(context->stack_b);
		context->stack_a = ft_blst_first(context->stack_a);
	}
	sort_small_stack(context);
	context->stack_b = ft_blst_first(context->stack_b);
	while (ft_lstsize((t_list *)context->stack_b) > 0)
		pop_b_push_a(context);
}

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
	context->stack_a = stack_create(argv + 1);
	context->stack_b = NULL;
}

void	sorter_start(char const *argv[])
{
	t_common_context	*context;

	context = ft_managed_malloc(sizeof(t_common_context));
	ft_memset(context, 0, sizeof(t_common_context));
	sorter_init(context, argv);

	context->stack_a = ft_blst_first(context->stack_a);
	context->stack_len = ft_lstsize((t_list *)context->stack_a);

	if (context->stack_len <= 2)
		sort_two(context);
	else if (context->stack_len <= 3)
		sort_small_stack(context);
	else
		sort_medium_stack(context);

	sorter_shutdown(context);
}

int	main(int argc, char const *argv[])
{
	if (argc <= 1)
		return (0);
	sorter_start(argv);
	return (0);
}
