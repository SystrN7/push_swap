/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruiz <seruiz@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:34:01 by fgalaup           #+#    #+#             */
/*   Updated: 2021/05/12 11:43:55 by seruiz           ###   ########lyon.fr   */
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

	size_t					stack_len;
	struct s_instruction	*instruction_set;
	t_bidirectional_list	*sort_instructions;
}				t_common_context;

#endif
