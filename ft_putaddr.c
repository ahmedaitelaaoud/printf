/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ela <aait-ela@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:23:42 by aait-ela          #+#    #+#             */
/*   Updated: 2025/11/11 15:51:41 by aait-ela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puthexa_ul(unsigned long n, size_t *count)
{
	char	*base;

	base = "0123456789abcdef";
	if (n > 15)
		ft_puthexa_ul((n / 16), count);
	ft_putchar(base[n % 16], count);
}

void	ft_putaddr(void *ptr, size_t *count)
{
	unsigned long	addr;

	addr = (unsigned long)ptr;
	if (addr == 0)
	{
		*count += write(1, "(nil)", 5);
		return ;
	}
	*count += write(1, "0x", 2);
	ft_puthexa_ul(addr, count);
}
