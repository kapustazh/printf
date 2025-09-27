/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atvii <atvii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:12:56 by atvii             #+#    #+#             */
/*   Updated: 2025/09/27 20:41:35 by atvii            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv_checker_3(const char c, va_list args, int count)
{
	if (c == 'c')
		count += ft_putchar((char)va_arg(args, int));
	if (c == 'd' || c == 'i')
		count += ft_nbr_base(va_arg(args, int), 10, 'd');
	else if (c == 'u')
		count += ft_unbr_base(va_arg(args, unsigned int), 10, 'd');
	else if (c == 'x')
		count += ft_unbr_base(va_arg(args, unsigned int), 16, 'x');
	else if (c == 'X')
		count += ft_unbr_base(va_arg(args, unsigned int), 16, 'X');
	else if (c == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_conv_checker_2(const char c, va_list args, int count)
{
	void		*ptr;
	const char	*str;

	if (c == 's')
	{
		str = va_arg(args, const char *);
		if (!str)
			count += ft_putstr("(null)");
		else
			count += ft_putstr(str);
	}
	else if (c == 'p')
	{
		ptr = va_arg(args, void *);
		if (!ptr)
			count += ft_putstr("(nil)");
		else
		{
			count += ft_putstr("0x");
			count += ft_unbr_base((unsigned long)ptr, 16, 'x');
		}
	}
	return (count);
}

int	ft_conv_checker(const char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 's' || c == 'p')
		count += ft_conv_checker_2(c, args, count);
	else
		count += ft_conv_checker_3(c, args, count);
	return (count);
}
