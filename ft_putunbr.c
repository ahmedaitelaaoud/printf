/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ela <aait-ela@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:28:06 by aait-ela          #+#    #+#             */
/*   Updated: 2025/11/11 12:30:37 by aait-ela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr(unsigned int n, size_t *count)
{
	if (n > 9)
		ft_putunbr(n / 10, count);
	ft_putchar((n % 10) + '0', count);
}
