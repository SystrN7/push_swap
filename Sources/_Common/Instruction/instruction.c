/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruiz <seruiz@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:36:34 by fgalaup           #+#    #+#             */
/*   Updated: 2021/05/12 11:54:19 by seruiz           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common_instruction.h"

void	intruction_read_exec(t_common_context *context)
{
	char	*line;
	int		read_status;
	int		i;

	read_status = FT_TRUE;
	while (read_status)
	{
		i = 0;
		ft_managed_free(line);
		read_status = get_next_line(standard_input, &line);
		if (line[0] == '\0')
			continue ;
		while (instruction_set[i].token != NULL)
		{
			if (ft_strncmp(line, instruction_set[i].token, 16) == 0)
			{
				instruction_set[i].do_instruction(context);
				break ;
			}
			i++;
		}
		if (instruction_set[i].token == NULL)
			error_fatal(ERROR_INSTRUCTION_UNKNOWN, line);
	}
	ft_managed_free(line);
}

void	intruction_add_exec(t_common_context *context, int instruction_code)
{
	long long	instruction_code_tmp;
	int			i;

	i = 0;
	while (instruction_set[i].token != NULL)
	{
		if (instruction_set[i].type == instruction_code)
		{
			instruction_set[i].do_instruction(context);
			break ;
		}
		i++;
	}
	if (instruction_set[i].token == NULL)
		error_fatal(ERROR_INSTRUCTION_UNKNOWN, "?");
	instruction_code_tmp = 0;
	instruction_code_tmp = (long long)instruction_code;
	ft_blst_new_back(
		&context->sort_instructions,
		(void *)instruction_code_tmp, NULL);
}

void	intruction_show_list(t_common_context *context)
{
	t_bidirectional_list	*it;
	int						i;

	it = ft_blst_first(context->sort_instructions);
	while (it)
	{
		i = 0;
		while (instruction_set[i].token != NULL)
		{
			if (instruction_set[i].type == (int)it->content)
			{
				ft_printf("%s\n", instruction_set[i].token);
				break ;
			}
			i++;
		}
		if (instruction_set[i].token == NULL)
			error_fatal(ERROR_INSTRUCTION_UNKNOWN, "?");
		it = it->next;
	}
}
