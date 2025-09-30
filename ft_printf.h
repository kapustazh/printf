/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atvii <atvii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 19:19:56 by atvii             #+#    #+#             */
/*   Updated: 2025/09/27 13:57:45 by atvii            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *conv, ...);
int	ft_conv_checker(const char c, va_list args);
int	ft_putstr(const char *str);
int	ft_putchar(const char c);
int	ft_conv_checker_2(const char c, va_list args, int count);
int	ft_conv_checker_3(const char c, va_list args, int count);
int	ft_unbr_base(unsigned long unbr, unsigned long base, char form);
int	ft_nbr_base(long nbr, int base, char form);

#endif