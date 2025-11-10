/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ela <aait-ela@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:12:17 by aait-ela          #+#    #+#             */
/*   Updated: 2025/11/10 11:14:50 by aait-ela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>

int	ft_printf(const char *format, ...);
void	ft_putchar(char c, size_t *count);
void	ft_putstr(char *s, size_t *count);

#endif
