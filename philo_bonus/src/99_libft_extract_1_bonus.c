/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   99_libft_extract_1_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:18:43 by isojo-go          #+#    #+#             */
/*   Updated: 2023/01/10 18:02:24 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

/* DESCRIPTION:
The isspace() function tests for the white-space characters. For any locale,
this includes the following standard characters:
``\t''``\n''``\v''``\f''``\r''`` ''
The value of the argument must be representable as an unsigned char or the
value of EOF.
The isspace() function returns zero if the character tests false and returns
non-zero if the character tests true.
---------------------------------------------------------------------------- */
int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

/* DESCRIPTION:
The isdigit() function tests for a decimal digit character. Regardless of
locale, this includes the following characters only: '0' through'9'. The
function returns zero if the character tests false and returns non-zero if the
character tests true.
The value of the argument must be representable as an unsigned char or the
value of EOF.
The isnumber() function behaves similarly to isdigit(), but may recognize
additional characters, depending on the current locale setting.
---------------------------------------------------------------------------- */
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static void	init_params(unsigned int *n, int *sign, unsigned int *digits)
{
	*n = 0;
	*sign = 1;
	*digits = 0;
}

/* DESCRIPTION:
The function tests for a valid integer in a full null terminated string.
Returns zero if the character tests false and returns non-zero if tests true.
---------------------------------------------------------------------------- */
int	ft_isint(char *s)
{
	unsigned int	n;
	int				sign;
	unsigned int	digits;

	init_params(&n, &sign, &digits);
	if (*s == '+' || *s == '-')
	{
		if (*s++ == '-')
			sign = -1;
	}
	while (*s)
	{
		if (ft_isdigit(*s) && digits < 11 && n <= 214748364)
		{
			if (n == 214748364 && (*s == '9' || (*s == '8' && sign == 1)))
				return (0);
			n = n * 10 + (*s++ - '0');
			digits++;
		}
		else
			return (0);
	}
	if (digits == 0)
		return (0);
	return (1);
}

/* DESCRIPTION:
The atoi() function converts the initial portion of the string pointed by str
to int representation.
It skips any space before the numbers, accepts one single optional sign
character (+ or -) and considers the all digits afterwards.
---------------------------------------------------------------------------- */
int	ft_atoi(const char *str)
{
	unsigned int	n;
	int				sign;
	size_t			i;

	n = 0;
	i = 0;
	sign = 1;
	while (*(str + i) && ft_isspace(*(str + i)))
		i++;
	if (*(str + i) == '+' || *(str + i) == '-')
	{
		if (*(str + i) == '-')
			sign = -1;
		i++;
	}
	while (*(str + i) && ft_isdigit(*(str + i)))
	{
		n = n * 10 + (*(str + i) - '0');
		i++;
	}
	return (sign * n);
}
