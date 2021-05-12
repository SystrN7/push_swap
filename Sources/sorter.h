/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruiz <seruiz@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:40:55 by fgalaup           #+#    #+#             */
/*   Updated: 2021/05/12 15:04:30 by seruiz           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTER_H
# define SORTER_H

# include "libft.h"

# include "common_error.h"
# include "common_stack.h"
# include "common_instruction.h"

typedef struct	s_pos_len
{
	int	pos;
	int	i;
}				t_pos_len;


void	sorter_init(t_common_context *context, char const *argv[]);
void	sorter_start(char const *argv[]);
void	sorter_shutdown(t_common_context *context);

void	ft_blst_show(t_bidirectional_list *stack);
void	generic_sorter(t_common_context *context);

#endif
