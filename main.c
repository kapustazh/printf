/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:23:31 by mnestere          #+#    #+#             */
/*   Updated: 2025/10/08 10:54:52 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_char(const char *conv, va_list args)
{
	if (*conv == '%' && *(conv + 1))
		return (ft_conv_checker(*(conv + 1), args));
	return (ft_putchar(*conv));
}

int	ft_printf(const char *conv, ...)
{
	va_list	args;
	int		printed;
	int		result;

	printed = 0;
	va_start(args, conv);
	while (*conv)
	{
		result = ft_handle_char(conv, args);
		if (result == -1)
			return (-1);
		printed += result;
		if (*conv == '%')
			conv += 2;
		else
			conv++;
	}
	va_end(args);
	return (printed);
}
