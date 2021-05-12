/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_instruction.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalaup <fgalaup@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 10:07:58 by fgalaup           #+#    #+#             */
/*   Updated: 2021/05/12 11:22:00 by fgalaup          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_INSTRUCTION_H
# define COMMON_INSTRUCTION_H

# include "libft.h"

# include "common.h"
# include "common_error.h"

void	swap_first_a_b(t_common_context *context);
void	swap_first_a(t_common_context *context);
void	swap_first_b(t_common_context *context);
void	pop_b_push_a(t_common_context *context);
void	pop_a_push_b(t_common_context *context);
void	rotate_a_b(t_common_context *context);
void	rotate_a(t_common_context *context);
void	rotate_b(t_common_context *context);
void	reverse_rotate_a_b(t_common_context *context);
void	reverse_rotate_a(t_common_context *context);
void	reverse_rotate_b(t_common_context *context);

enum e_instruction_type
{
	STOP = 0,
	INSTRUCTION_SWAP_FIRST_A_B,
	INSTRUCTION_SWAP_FIRST_A,
	INSTRUCTION_SWAP_FIRST_B,
	INSTRUCTION_POP_B_PUSH_A,
	INSTRUCTION_POP_A_PUSH_B,
	INSTRUCTION_ROTATE_A_B,
	INSTRUCTION_ROTATE_A,
	INSTRUCTION_ROTATE_B,
	INSTRUCTION_REVERSE_ROTATE_A_B,
	INSTRUCTION_REVERSE_ROTATE_A,
	INSTRUCTION_REVERSE_ROTATE_B,
};

struct s_instruction
{
	int			type;
	const char	*token;
	void		(*do_instruction)(t_common_context *context);
} const static instruction_set[] = {
	{INSTRUCTION_SWAP_FIRST_A_B, "ss", &swap_first_a_b},
	{INSTRUCTION_SWAP_FIRST_A, "sa", &swap_first_a},
	{INSTRUCTION_SWAP_FIRST_B, "sb", &swap_first_b},
	{INSTRUCTION_POP_B_PUSH_A, "pa", &pop_b_push_a},
	{INSTRUCTION_POP_A_PUSH_B, "pb", &pop_a_push_b},
	{INSTRUCTION_ROTATE_A_B, "rr", &rotate_a_b},
	{INSTRUCTION_ROTATE_A, "ra", &rotate_a},
	{INSTRUCTION_ROTATE_B, "rb", &rotate_b},
	{INSTRUCTION_REVERSE_ROTATE_A_B, "rrr", &reverse_rotate_a_b},
	{INSTRUCTION_REVERSE_ROTATE_A, "rra", &reverse_rotate_a},
	{INSTRUCTION_REVERSE_ROTATE_B, "rrb", &reverse_rotate_b},
	{STOP, NULL, NULL}
};

void	intruction_read_exec(t_common_context *context);
void	intruction_add_exec(t_common_context *context, int instuction_code);
void	intruction_show_list(t_common_context *context);

#endif
