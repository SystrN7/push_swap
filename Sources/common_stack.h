/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_stack.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalaup <fgalaup@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:37:31 by fgalaup           #+#    #+#             */
/*   Updated: 2021/05/12 13:04:21 by fgalaup          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_STACK_H
# define COMMON_STACK_H

# include "libft.h"

# include "common.h"
# include "common_error.h"

t_blst	stack_create(char const *argv[]);
t_bool	stack_is_sort(t_bidirectional_list *stack);
t_bool	stack_double_exist(t_bidirectional_list *stack, void *number);
void	stack_create_continuous_list(t_common_context *context);


#endif
