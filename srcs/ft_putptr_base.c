/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfiszbin <vfiszbin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:51:21 by vfiszbin          #+#    #+#             */
/*   Updated: 2021/12/18 09:37:19 by vfiszbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	check_init_error2(char *base)
{
	int	i;
	int	j;

	if (base[0] == 0 || base[1] == 0)
		return (1);
	i = 0;
	j = 0;
	while (base[i] != '\0')
	{
		j = i;
		if (base[i] == '+' || base[i] == '-'
			|| base[i] <= 32 || base[i] > 126)
			return (1);
		while (base[j] != '\0')
		{
			j++;
			if (base[j] == base[i])
				return (1);
		}
		i++;
	}
	return (0);
}

void	ft_putptr_base(unsigned long long nbr, char *base)
{
	int		base_len;
	long	num;

	num = nbr;
	if (check_init_error2(base) == 0)
	{
		if (num < 0)
		{
			ft_putchar_fd('-', 1);
			num = num * (-1);
		}
		base_len = 0;
		while (base[base_len])
			base_len++;
		if (num >= base_len)
		{
			ft_putnbr_base(num / base_len, base);
			ft_putnbr_base(num % base_len, base);
		}
		if (num < base_len)
			ft_putchar_fd(base[num], 1);
	}
}
