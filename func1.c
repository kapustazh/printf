/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:23:17 by mnestere          #+#    #+#             */
/*   Updated: 2025/10/07 17:19:47 by mnestere         ###   ########.fr       */
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
	if (form == 'X')
		digits = "0123456789ABCDEF";
	else if (form == 'x')
		digits = "0123456789abcdef";
	else
		digits = "0123456789";
	if (unbr >= base)
		num += ft_unbr_base(unbr / base, base, form);
	result = ft_putchar(digits[unbr % base]);
	if (result == -1)
		return (-1);
	num++;
	return (num);
}

int	ft_nbr_base(long nbr, int base, char form)
{
	unsigned long	unbr;
	int				num;

	num = 0;
	if (form == 'd' && nbr < 0)
	{
		num += ft_putchar('-');
		if (num == -1)
			return (-1);
		unbr = (unsigned long)(-nbr);
	}
	else
		unbr = (unsigned long)nbr;
	num += ft_unbr_base(unbr, base, form);
	if (num == -1)
		return (-1);
	return (num);
}
