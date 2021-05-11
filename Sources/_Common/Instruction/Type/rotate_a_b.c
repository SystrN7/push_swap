/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruiz <seruiz@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:37:08 by fgalaup           #+#    #+#             */
/*   Updated: 2021/05/10 16:28:13 by seruiz           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common_instruction.h"

void	rotate_a_b(t_common_context *context)
{
	rotate_a(context);
	rotate_b(context);
	write (1, "rr\n", 3);
}
