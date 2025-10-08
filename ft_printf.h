/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:23:23 by mnestere          #+#    #+#             */
/*   Updated: 2025/10/08 10:54:59 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *conv, ...);
int	ft_putstr(const char *str);
int	ft_putchar(const char c);
int	ft_unbr_base(unsigned long unbr, unsigned long base, char form);
int	ft_nbr_base(long nbr, int base, char form);
int	ft_conv_checker_s(va_list args, int count);
int	ft_conv_checker_p(va_list args, int count);
int	ft_conv_checker(const char c, va_list args);
int	ft_conv_checker_cdiu(const char c, va_list args, int count);
int	ft_conv_checker_xxper(const char c, va_list args, int count);

#endif