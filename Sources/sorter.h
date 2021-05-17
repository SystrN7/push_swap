/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalaup <fgalaup@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:40:55 by fgalaup           #+#    #+#             */
/*   Updated: 2021/05/17 11:32:46 by fgalaup          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTER_H
# define SORTER_H

# include "libft.h"

# include "common_error.h"
# include "common_stack.h"
# include "common_instruction.h"

typedef struct s_pos_len
{
	int	pos;
	int	i;
}				t_pos_len;

void	sorter_init(t_common_context *context, char const *argv[]);
void	sorter_start(char const *argv[]);
void	sorter_shutdown(t_common_context *context);

void	ft_blst_show(t_bidirectional_list *stack);
void	generic_sorter(t_common_context *context);

// Algo
void	sort_two(t_common_context *context);
void	sort_small_stack(t_common_context *cnt);
int		ft_get_min_pos(t_common_context *context);
void	sort_medium_stack(t_common_context *context);

#endif
