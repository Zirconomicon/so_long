/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduric <iduric@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:07:26 by iduric            #+#    #+#             */
/*   Updated: 2024/02/27 09:36:57 by iduric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_put_unsigned_nbr(unsigned int n);
int		ft_putstr(const char *str);
int		ft_putchar(int c);
int		ft_percent(void);
int		ft_lhexa(unsigned long long n);
int		ft_uhexa(unsigned long long n);
int		ft_putptr(void *ptr);
int		nbr_size(int n);
int		size_of_unsigned_nbr(unsigned long long n);
int		hexa_size(unsigned long long n);
char	*ft_strchr(const char *s, int c);
int		ft_percheck(const char *conv);
int		hasPercentSign(const char *str);
int		ft_tamis(char conv, va_list etc);
int		ft_printf(const char *conv, ...);
int		ft_putnbr(int n);
int		ft_putnbr(int n);

#endif
