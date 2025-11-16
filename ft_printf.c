/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ela <aait-ela@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:29:38 by aait-ela          #+#    #+#             */
/*   Updated: 2025/11/10 11:29:38 by aait-ela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_conversion(char spec, va_list args, size_t *count)
{
	if (spec == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (spec == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (spec == 'd' || spec == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (spec == 'p')
		ft_putaddr(va_arg(args, void *), count);
	else if (spec == 'u')
		ft_putunbr(va_arg(args, unsigned int), count);
	else if (spec == 'x' || spec == 'X')
		ft_puthexa(va_arg(args, unsigned int), count, spec);
	else if (spec == '%')
		ft_putchar('%', count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	count;
	size_t	i;

	va_start(args, format);
	count = 0;
	i = 0;
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			handle_conversion(format[i], args, &count);
		}
		else
			ft_putchar(format[i], &count);
		i++;
	}
	va_end(args);
	return ((int)count);
}
