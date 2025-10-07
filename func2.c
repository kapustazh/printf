/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:23:10 by mnestere          #+#    #+#             */
/*   Updated: 2025/10/07 17:49:04 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	minus_one_checker(const char c, int result, int count, int (*f))
// {
// }

int	ft_conv_checker_3(const char c, va_list args, int count)
{
	int	result;

	if (c == 'c')
	{
		result = ft_putchar(va_arg(args, int));
		if (result == -1)
			return (-1);
		count += result;
	}
	if (c == 'd' || c == 'i')
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
	else if (c == 'x')
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

int	ft_conv_checker_2(const char c, va_list args, int count)
{
	int			result;
	void		*ptr;
	const char	*str;

	if (c == 's')
	{
		str = va_arg(args, const char *);
		if (!str)
		{
			result = ft_putstr("(null)");
			if (result == -1)
				return (-1);
			count += result;
		}
		else
			result = ft_putstr(str);
		if (result == -1)
			return (-1);
		count += result;
	}
	else if (c == 'p')
	{
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
