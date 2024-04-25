/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaing <jtaing@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:29:03 by jtaing            #+#    #+#             */
/*   Updated: 2024/03/20 09:49:47 by jtaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
	{
		ft_print_str("(null)");
		return (6);
	}
	while (*str)
	{
		ft_print_char((int)*str);
		count++;
		str++;
	}
	return (count);
}
