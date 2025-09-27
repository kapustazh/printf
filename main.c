/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atvii <atvii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 19:39:53 by atvii             #+#    #+#             */
/*   Updated: 2025/09/27 20:41:34 by atvii            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *conv, ...)
{
	va_list	args;
	int		printed;

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
			printed += ft_putchar(*conv);
			conv++;
		}
	}
	va_end(args);
	return (printed);
}
