/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_error.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalaup <fgalaup@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 12:32:38 by fgalaup           #+#    #+#             */
/*   Updated: 2021/05/11 16:06:39 by fgalaup          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_ERROR_H
# define COMMON_ERROR_H

# include <errno.h>
# include <string.h>
# include <stdio.h>

# include "libft.h"

enum					e_error_code
{
	ERROR_STD = -1,
	SUCCESS = 0,
	ERROR_MALLOC,
	ERROR_UNDIFINED,
	ERROR_ARG_NOT_NUMBER,
	ERROR_ARG_INT_BIGGER,
	ERROR_ARG_NUMBER_ALREADY_EXISTS,
	ERROR_INSTRUCTION_UNKNOWN,
};

struct		s_error_messages
{
	int					code;
	char				*message;
} const static error_messages[] = {
	{ERROR_UNDIFINED, "undifined error (Just take a cooffe ☕)."},
	{ERROR_STD, "is not an error for my bro."},
	{ERROR_ARG_NOT_NUMBER, "%s: numeric argument is required"},
	{ERROR_ARG_INT_BIGGER, "`%s': numeric is bigger than interger"},
	{ERROR_ARG_NUMBER_ALREADY_EXISTS, "`%s': number already exists in stack"},
	{ERROR_INSTRUCTION_UNKNOWN, "`%s': unvalid instruction found"},
	{0, NULL}
};

char	*error_get_message(int error_code);
void	error_print_messages(int error_code, va_list arg);

void	error_message(int error_code, ...);
void	error_fatal(int error_code, ...);

#endif
