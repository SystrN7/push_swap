/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalaup <fgalaup@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:34:01 by fgalaup           #+#    #+#             */
/*   Updated: 2021/05/07 17:16:57 by fgalaup          ###   ########lyon.fr   */
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

	t_list					*instruction_set;
	t_list					*sort_instructions;
}				t_common_context;

#endif
