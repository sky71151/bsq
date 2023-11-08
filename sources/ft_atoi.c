/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperez-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:22:18 by rperez-t          #+#    #+#             */
/*   Updated: 2023/11/07 09:03:36 by rperez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	int	space;
	int	horizontal;
	int	carriage;

	space = (c == ' ');
	horizontal = ('\t' <= c);
	carriage = (c <= '\r');
	return ((horizontal && carriage) || space);
}

int	ft_signcheck(char c)
{
	int	pose;
	int	nege;

	pose = (c == '+');
	nege = (c == '-');
	return (pose || nege);
}

int	ft_numbers(char c)
{
	int	digits;

	digits = (('0' <= c) && (c <= '9'));
	return (digits);
}

int	ft_atoi(char *str)
{
	int	result;
	int	sign;
	int	i;
	int	transformer;

	result = 0;
	sign = 1;
	i = 0;
	transformer = '0';
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (ft_numbers(str[i]))
	{
		result = ((result * 10) + (str[i] - transformer));
		i++;
	}
	result = result * sign;
	return (result);
}
