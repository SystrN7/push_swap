/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalaup <fgalaup@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:36:29 by fgalaup           #+#    #+#             */
/*   Updated: 2021/05/17 14:08:58 by fgalaup          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "common_error.h"

	// t_common_context *context,
void	error_fatal(
	int error_code,
	 ...
)
{
	va_list	args;

	ft_putstr_fd(standard_error, "Error ");
	va_start(args, error_code);
	error_print_messages(error_code, args);
	va_end(args);
	if (ft_managed_termination_function(NULL))
		ft_managed_termination_function(NULL)
		(ft_managed_termination_params(NULL));
}

void	error_message(
	int error_code,
	 ...
)
{
	va_list	args;

	ft_putstr_fd(standard_error, "Error ");
	va_start(args, error_code);
	error_print_messages(error_code, args);
	va_end(args);
}

void	error_print_messages(
	int error_code,
	va_list args
)
{
	char	*buffer;
	int		size;
	char	*error_message;

	buffer = NULL;
	error_message = error_get_message(error_code);
	size = ft_format(error_message, args, &buffer);
	if (size < 0)
		return ;
	if (size > 0)
		size--;
	write(standard_error, buffer, size);
	write(standard_error, "\n", 1);
	ft_managed_free(buffer);
}

char	*error_get_message(int	error_code)
{
	size_t	i;

	if (error_code == ERROR_STD)
		return (strerror(errno));
	i = 0;
	while (error_messages[i].code != 0 && error_messages[i].message != NULL)
	{
		if (error_messages[i].code == error_code)
			return (error_messages[i].message);
		i++;
	}
	return (NULL);
}
