/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaing <jtaing@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:29:09 by jtaing            #+#    #+#             */
/*   Updated: 2024/03/19 13:29:11 by jtaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count = ft_print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += ft_print_str(va_arg(ap, char *));
	else if (specifier == 'd')
		count += ft_print_nbr(va_arg(ap, int), 10);
	else if (specifier == 'i')
		count += ft_print_nbr((long)va_arg(ap, int), 10);
	else if (specifier == 'u')
		count += ft_print_nbr(va_arg(ap, unsigned int), 10);
	else if (specifier == 'x')
		count += ft_print_nbr((long)va_arg(ap, unsigned int), 16);
	else if (specifier == 'X')
		count += ft_print_hexa((long)va_arg(ap, unsigned int), 16);
	else if (specifier == 'p')
		count += ft_print_ptr((long unsigned)(va_arg(ap, void *)));
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	if (!format)
		return (0);
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
			count += print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}
