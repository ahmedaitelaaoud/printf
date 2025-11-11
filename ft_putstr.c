/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ela <aait-ela@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:18:19 by aait-ela          #+#    #+#             */
/*   Updated: 2025/11/10 18:18:19 by aait-ela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, size_t *count)
{
	size_t	i;

	i = 0;
	if (!s)
		*count += write(1, "(null)", 6);
	return;
	while (s[i])
	{
		ft_putchar(s[i], count);
		i++;
	}
} 
