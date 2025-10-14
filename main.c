/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atvii <atvii@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:23:31 by mnestere          #+#    #+#             */
/*   Updated: 2025/10/15 00:56:11 by atvii            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *conv, ...)
{
	va_list	args;
	int		printed;
	int		result;

	printed = 0;
	va_start(args, conv);
	while (*conv)
	{
		if (*conv == '%' && (*(conv + 1)))
		{
			conv++;
			result = ft_conv_checker(*conv, args);
		}
		else
			result = ft_putchar(*conv);
		if (result == -1)
			return (-1);
		printed += result;
		conv++;
	}
	va_end(args);
	return (printed);
}

// #include "ft_printf.h"
// #include <limits.h>
// #include <stdio.h>

// int	main(void)
// {
// 	printf("--- 1. Testing NULL String (%%s) ---\n");
// 	printf("printf:    >");
// 	printf("%s", NULL);
// 	printf("<\n");
// 	ft_printf("ft_printf: >");
// 	ft_printf("%s", NULL);
// 	ft_printf("<\n\n");

// 	printf("--- 2. Testing NULL Pointer (%%p) ---\n");
// 	printf("printf:    >");
// 	printf("%p", NULL);
// 	printf("<\n");
// 	ft_printf("ft_printf: >");
// 	ft_printf("%p", NULL);
// 	ft_printf("<\n\n");

// 	printf("--- 3. Testing Zero (%%d) ---\n");
// 	printf("printf:    >");
// 	printf("%d", 0);
// 	printf("<\n");
// 	ft_printf("ft_printf: >");
// 	ft_printf("%d", 0);
// 	ft_printf("<\n\n");

// 	printf("--- 4. Testing INT_MIN (%%d) ---\n");
// 	printf("printf:    >");
// 	printf("%d", INT_MIN);
// 	printf("<\n");
// 	ft_printf("ft_printf: >");
// 	ft_printf("%d", INT_MIN);
// 	ft_printf("<\n\n");

// 	printf("--- 5. Testing INT_MAX (%%d) ---\n");
// 	printf("printf:    >");
// 	printf("%d", INT_MAX);
// 	printf("<\n");
// 	ft_printf("ft_printf: >");
// 	ft_printf("%d", INT_MAX);
// 	ft_printf("<\n\n");

// 	printf("--- 6. Testing UINT_MAX (%%u) ---\n");
// 	printf("printf:    >");
// 	printf("%u", UINT_MAX);
// 	printf("<\n");
// 	ft_printf("ft_printf: >");
// 	ft_printf("%u", UINT_MAX);
// 	ft_printf("<\n\n");

// 	printf("--- 7. Testing UINT_MAX (%%x) ---\n");
// 	printf("printf:    >");
// 	printf("%x", UINT_MAX);
// 	printf("<\n");
// 	ft_printf("ft_printf: >");
// 	ft_printf("%x", UINT_MAX);
// 	ft_printf("<\n\n");

// 	printf("--- 8. Testing UINT_MAX (%%X) ---\n");
// 	printf("printf:    >");
// 	printf("%X", UINT_MAX);
// 	printf("<\n");
// 	ft_printf("ft_printf: >");
// 	ft_printf("%X", UINT_MAX);
// 	ft_printf("<\n\n");

// 	printf("--- 9. Testing Null Char (%%c) ---\n");
// 	printf("printf:    >");
// 	printf("The char is %c here", '\0');
// 	printf("<\n");
// 	ft_printf("ft_printf: >");
// 	ft_printf("The char is %c here", '\0');
// 	ft_printf("<\n\n");

// 	printf("--- 10. Testing Empty String ---\n");
// 	printf("printf:    >");
// 	printf("");
// 	printf("<\n");
// 	ft_printf("ft_printf: >");
// 	ft_printf("");
// 	ft_printf("<\n\n");

// 	printf("--- 11. Testing String Ending with %% ---\n");
// 	printf("printf:    >");
// 	printf("This is a test %%");
// 	printf("<\n");
// 	ft_printf("ft_printf: >");
// 	ft_printf("This is a test %%");
// 	ft_printf("<\n\n");

// 	printf("--- 12. Testing Mixed Specifiers and %% ---\n");
// 	printf("printf:    >");
// 	printf("%d%s%p%%%%%%blablabla", 123, "abc", NULL);
// 	printf("<\n");
// 	ft_printf("ft_printf: >");
// 	ft_printf("%d%s%p%%%%%%blablabla", 123, "abc", NULL);
// 	ft_printf("<\n\n");

// 	return (0);
// }