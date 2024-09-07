/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowander <jowander@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:30:18 by jowander          #+#    #+#             */
/*   Updated: 2024/06/28 10:29:33 by jowander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_char(va_list *args)
{
	unsigned char	c;

	c = (unsigned char)va_arg(*args, int);
	return (write(1, &c, 1));
}

int	ft_print_string(va_list *args)
{
	char	*str;
	int		count;

	str = va_arg(*args, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	count = 0;
	while (str[count])
	{
		ft_putchar(str[count]);
		count++;
	}
	return (count);
}
