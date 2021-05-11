/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruiz <seruiz@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:40:55 by fgalaup           #+#    #+#             */
/*   Updated: 2021/05/10 15:52:18 by seruiz           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTER_H
# define SORTER_H

# include "libft.h"

# include "common_error.h"
# include "common_stack.h"
# include "common_instruction.h"

void	sorter_init(t_common_context *context, char const *argv[]);
void	sorter_start(char const *argv[]);
void	sorter_shutdown(t_common_context *context);

#endif
