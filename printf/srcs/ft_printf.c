/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowander <jowander@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 20:34:39 by jowander          #+#    #+#             */
/*   Updated: 2024/06/28 10:29:36 by jowander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_handle_conversion(format[i], &args);
		}
		else
		{
			ft_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

int	ft_handle_conversion(char type, va_list *args)
{
	if (type == 'c')
		return (ft_print_char(args));
	if (type == 's')
		return (ft_print_string(args));
	if (type == 'p')
		return (ft_print_pointer(args));
	if (type == 'd' || type == 'i')
		return (ft_print_int(args));
	if (type == 'u')
		return (ft_print_uint(args));
	if (type == 'x')
		return (ft_print_hex(args, false));
	if (type == 'X')
		return (ft_print_hex(args, true));
	if (type == '%')
	{
		ft_putchar('%');
		return (1);
	}
	return (0);
}
