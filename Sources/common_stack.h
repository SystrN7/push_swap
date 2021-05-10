/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_stack.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalaup <fgalaup@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:37:31 by fgalaup           #+#    #+#             */
/*   Updated: 2021/05/10 10:25:42 by fgalaup          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_STACK_H
# define COMMON_STACK_H

# include "libft.h"

# include "common.h"
# include "common_error.h"

t_blst	stack_create(char const *argv[]);
t_bool	stack_is_sort(t_bidirectional_list *stack);



#endif
