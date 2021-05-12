/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalaup <fgalaup@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:34:01 by fgalaup           #+#    #+#             */
/*   Updated: 2021/05/11 13:21:19 by fgalaup          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "libft.h"

typedef struct s_common_context
{
	int						status;

	t_bidirectional_list	*stack_a;
	t_bidirectional_list	*stack_b;

	struct s_instruction	*instruction_set;
	t_bidirectional_list	*sort_instructions;
}				t_common_context;

#endif
