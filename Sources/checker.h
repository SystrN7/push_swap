/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruiz <seruiz@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:41:41 by fgalaup           #+#    #+#             */
/*   Updated: 2021/05/10 15:51:40 by seruiz           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"

# include "common_error.h"
# include "common_stack.h"
# include "common_instruction.h"

void	checker_init(t_common_context *context, char const *argv[]);
void	checker_start(char const *argv[]);
void	checker_shutdown(t_common_context *context);

#endif
