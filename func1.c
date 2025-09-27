/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atvii <atvii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:46:01 by atvii             #+#    #+#             */
/*   Updated: 2025/09/27 18:02:49 by atvii            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(const char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_unbr_base(unsigned long unbr, unsigned long base, char form)
{
	int		num;
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
	ft_putchar(digits[unbr % base]);
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
		unbr = (unsigned long)(-nbr);
	}
	else
		unbr = (unsigned long)nbr;
	num += ft_unbr_base(unbr, base, form);
	return (num);
}
