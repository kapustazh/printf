/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atvii <atvii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:23:10 by mnestere          #+#    #+#             */
/*   Updated: 2025/10/07 20:42:31 by atvii            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv_checker_cdiu(const char c, va_list args, int count)
{
	int	result;

	if (c == 'c')
	{
		result = ft_putchar((unsigned char)va_arg(args, int));
		if (result == -1)
			return (-1);
		count += result;
	}
	else if (c == 'd' || c == 'i')
	{
		result = ft_nbr_base(va_arg(args, int), 10, 'd');
		if (result == -1)
			return (-1);
		count += result;
	}
	else if (c == 'u')
	{
		result = ft_unbr_base(va_arg(args, unsigned int), 10, 'd');
		if (result == -1)
			return (-1);
		count += result;
	}
	return (count);
}

int	ft_conv_checker_xxper(const char c, va_list args, int count)
{
	int	result;

	if (c == 'x')
	{
		result = ft_unbr_base(va_arg(args, unsigned int), 16, 'x');
		if (result == -1)
			return (-1);
		count += result;
	}
	else if (c == 'X')
	{
		result = ft_unbr_base(va_arg(args, unsigned int), 16, 'X');
		if (result == -1)
			return (-1);
		count += result;
	}
	else if (c == '%')
	{
		result = ft_putchar('%');
		if (result == -1)
			return (-1);
		count += result;
	}
	return (count);
}

int	ft_conv_checker_s(va_list args, int count)
{
	int			result;
	const char	*str;

	str = va_arg(args, const char *);
	if (!str)
		result = ft_putstr("(null)");
	else
		result = ft_putstr(str);
	if (result == -1)
		return (-1);
	count += result;
	return (count);
}

int	ft_conv_checker_p(va_list args, int count)
{
	int		result;
	void	*ptr;

	ptr = va_arg(args, void *);
	if (!ptr)
	{
		result = ft_putstr("(nil)");
		if (result == -1)
			return (-1);
		count += result;
	}
	else
	{
		result = ft_putstr("0x");
		if (result == -1)
			return (-1);
		count += result;
		result = ft_unbr_base((unsigned long)ptr, 16, 'x');
		if (result == -1)
			return (-1);
		count += result;
	}
	return (count);
}

int	ft_conv_checker(const char c, va_list args)
{
	int	printed;

	printed = 0;
	if (c == 's')
		printed += ft_conv_checker_s(args, printed);
	else if (c == 'p')
		printed += ft_conv_checker_p(args, printed);
	else if (c == 'c' || c == 'd' || c == 'i' || c == 'u')
		printed += ft_conv_checker_cdiu(c, args, printed);
	else
		printed += ft_conv_checker_xxper(c, args, printed);
	return (printed);
}
