/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:53:08 by mnestere          #+#    #+#             */
/*   Updated: 2025/10/24 12:53:10 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(const char c)
{
	int	result;

	result = write(1, &c, 1);
	if (result == -1)
		return (-1);
	return (1);
}

int	ft_putstr(const char *str)
{
	int	result;
	int	i;

	i = 0;
	while (str[i])
	{
		result = ft_putchar(str[i]);
		if (result == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_unbr_base(unsigned long unbr, unsigned long base, char form)
{
	int		num;
	int		result;
	char	*digits;

	num = 0;
	digits = "0123456789";
	if (form == 'X')
		digits = "0123456789ABCDEF";
	else if (form == 'x')
		digits = "0123456789abcdef";
	if (unbr >= base)
	{
		result = ft_unbr_base(unbr / base, base, form);
		if (result == -1)
			return (-1);
		num += result;
	}
	if (ft_putchar(digits[unbr % base]) == -1)
		return (-1);
	num++;
	return (num);
}

int	ft_nbr_base(long nbr, int base, char form)
{
	unsigned long	unbr;
	int				num;
	int				result;

	num = 0;
	if (form == 'd' && nbr < 0)
	{
		result = ft_putchar('-');
		if (result == -1)
			return (-1);
		num += result;
		unbr = (unsigned long)(-nbr);
	}
	else
		unbr = (unsigned long)nbr;
	result = ft_unbr_base(unbr, base, form);
	if (result == -1)
		return (-1);
	num += result;
	return (num);
}
