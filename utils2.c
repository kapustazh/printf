/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:23:10 by mnestere          #+#    #+#             */
/*   Updated: 2025/10/17 11:18:08 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv_checker_cdiu(const char c, va_list args)
{
	int	result;

	result = 0;
	if (c == 'c')
	{
		result = ft_putchar((unsigned char)va_arg(args, int));
		if (result == -1)
			return (-1);
	}
	else if (c == 'd' || c == 'i')
	{
		result = ft_nbr_base(va_arg(args, int), 10, 'd');
		if (result == -1)
			return (-1);
	}
	else if (c == 'u')
	{
		result = ft_unbr_base(va_arg(args, unsigned int), 10, 'd');
		if (result == -1)
			return (-1);
	}
	return (result);
}

int	ft_conv_checker_xxper(const char c, va_list args)
{
	int	result;

	result = 0;
	if (c == 'x')
	{
		result = ft_unbr_base(va_arg(args, unsigned int), 16, 'x');
		if (result == -1)
			return (-1);
	}
	else if (c == 'X')
	{
		result = ft_unbr_base(va_arg(args, unsigned int), 16, 'X');
		if (result == -1)
			return (-1);
	}
	else if (c == '%')
	{
		result = ft_putchar('%');
		if (result == -1)
			return (-1);
	}
	return (result);
}

int	ft_conv_checker_s(va_list args)
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
	return (result);
}

int	ft_conv_checker_p(va_list args)
{
	int		result;
	void	*ptr;
	int		tmp;

	ptr = va_arg(args, void *);
	if (!ptr)
	{
		result = ft_putstr("(nil)");
		if (result == -1)
			return (-1);
	}
	else
	{
		result = ft_putstr("0x");
		if (result == -1)
			return (-1);
		tmp = ft_unbr_base((unsigned long)ptr, 16, 'x');
		if (result == -1)
			return (-1);
		result += tmp;
	}
	return (result);
}

int	ft_conv_checker(const char c, va_list args)
{
	if (c == 's')
		return (ft_conv_checker_s(args));
	else if (c == 'p')
		return (ft_conv_checker_p(args));
	else if (c == 'c' || c == 'd' || c == 'i' || c == 'u')
		return (ft_conv_checker_cdiu(c, args));
	else
		return (ft_conv_checker_xxper(c, args));
}
