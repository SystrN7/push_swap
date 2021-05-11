/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_first_a_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruiz <seruiz@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:31:36 by fgalaup           #+#    #+#             */
/*   Updated: 2021/05/10 16:29:03 by seruiz           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common_instruction.h"

void	swap_first_a_b(t_common_context *context)
{
	swap_first_a(context);
	swap_first_b(context);
	write (1, "ss\n", 3);
}
