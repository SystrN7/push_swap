/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalaup <fgalaup@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:36:34 by fgalaup           #+#    #+#             */
/*   Updated: 2021/05/10 13:49:03 by fgalaup          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common_instruction.h"

void	intruction_exec(t_common_context *context)
{
	char	*line;
	int		read_status;
	int		i;

	line = NULL;
	read_status = FT_TRUE;
	while (read_status)
	{
		i = 0;
		read_status = get_next_line(standard_input, &line);
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
}
