/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowander <jowander@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:30:03 by jowander          #+#    #+#             */
/*   Updated: 2024/06/28 10:29:38 by jowander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_int(va_list *args)
{
	long	num;
	int		count;

	num = va_arg(*args, int);
	count = 0;
	if (num < 0)
	{
		ft_putchar('-');
		num = -num;
		count++;
	}
	return (ft_print_long(num) + count);
}

int	ft_print_uint(va_list *args)
{
	return (ft_print_long(va_arg(*args, unsigned int)));
}

int	ft_print_long(long num)
{
	int	count;

	count = 0;
	if (num >= 10)
		count += ft_print_long(num / 10);
	ft_putchar(num % 10 + '0');
	return (count + 1);
}
