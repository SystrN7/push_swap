/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalaup <fgalaup@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:36:34 by fgalaup           #+#    #+#             */
/*   Updated: 2021/05/10 11:16:15 by fgalaup          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common_instruction.h"

void	intruction_create_list(t_common_context *context)
{
	char	*line;
	int		read_status;

	line = NULL;
	read_status = FT_TRUE;
	while (read_status)
	{
		read_status = get_next_line(standard_input, &line);
		parse_instruction_list(context, line);
	}
}



void	parse_instruction_list(t_common_context *context, char *line)
{
	int		i;

	i = 0;
	while (((struct s_instruction *)instruction_set)[i].token != NULL)
	{
		if (ft_strncmp(line, instruction_set[i].token, 16) == 0)
		{
			
		}
	}
	error_fatal(ERROR_INSTRUCTION_UNKNOWN, line);
}
