/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:12:51 by antoinemura       #+#    #+#             */
/*   Updated: 2024/05/26 14:39:38 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

t_counter	*new_counter()
{
	t_counter	*counter;

	counter = ft_calloc(sizeof(t_counter *), 1);
	counter->c_count = -1;
	counter->e_count = -1;
	counter->p_count = -1;
}

void	free_counter(t_counter *counter)
{
	free(counter);
}
