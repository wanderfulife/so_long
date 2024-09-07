/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowander <jowander@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:29:57 by jowander          #+#    #+#             */
/*   Updated: 2024/06/28 10:29:42 by jowander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>
# include <unistd.h>

void	ft_putchar(char c);
int		ft_print_char(va_list *args);
int		ft_print_string(va_list *args);
int		ft_print_long(long num);
int		ft_print_int(va_list *args);
int		ft_print_uint(va_list *args);
int		ft_print_num_as_hex(unsigned long long num, bool uppercase);
int		ft_print_hex(va_list *args, bool uppercase);
int		ft_print_hex_address(uintptr_t addr);
int		ft_print_pointer(va_list *args);
int		ft_handle_conversion(char type, va_list *args);
int		ft_printf(const char *format, ...);

#endif