/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_a_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalaup <fgalaup@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:04:02 by fgalaup           #+#    #+#             */
/*   Updated: 2021/05/07 17:09:08 by fgalaup          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common_stack.h"

void	reverse_rotate_a_b(t_common_context *context)
{
	reverse_rotate_a(context);
	reverse_rotate_b(context);
}
