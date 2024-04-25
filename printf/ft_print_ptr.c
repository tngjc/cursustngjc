/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaing <jtaing@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:28:57 by jtaing            #+#    #+#             */
/*   Updated: 2024/03/19 13:28:58 by jtaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(long unsigned n)
{
	long unsigned	temp;
	char			final[256];
	int				i;
	int				count;

	i = 0;
	count = 0;
	if (!n)
	{
		ft_print_str("(nil)");
		return (5);
	}
	while (n > 0)
	{
		temp = n % 16;
		final[i++] = "0123456789abcdef"[temp];
		n /= 16;
	}
	count += write(1, "0x", 2);
	while (--i >= 0)
		count += write(1, &final[i], 1);
	return (count);
}
