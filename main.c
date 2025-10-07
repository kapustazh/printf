/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:23:31 by mnestere          #+#    #+#             */
/*   Updated: 2025/10/07 17:44:03 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *conv, ...)
{
	va_list	args;
	int		printed;
	int		result;

	printed = 0;
	va_start(args, conv);
	while (*conv)
	{
		if (*conv == '%')
		{
			conv++;
			if (*conv)
				printed += ft_conv_checker(*conv, args);
			conv++;
		}
		else
		{
			result = ft_putchar(*conv);
			if (printed == -1)
				return (-1);
			printed += result;
			conv++;
		}
	}
	va_end(args);
	return (printed);
}
