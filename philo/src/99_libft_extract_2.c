/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   99_libft_extract_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:24:47 by isojo-go          #+#    #+#             */
/*   Updated: 2023/01/04 22:49:25 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/* DESCRIPTION:
Outputs the char c to the file descriptor fd.
The function returns the number of characters printed and -1 if fails to print.
---------------------------------------------------------------------------- */
int	ft_putchar_fd(int c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

/* DESCRIPTION:
Outputs the string s to the file descriptor fd.
The function returns the number of characters printed and -1 if fails to print.
---------------------------------------------------------------------------- */
int	ft_putstr_fd(char *str, int fd)
{
	int	count;

	count = 0;
	if (!str)
		return (write(fd, "(null)", 6));
	while (*str)
	{
		count += ft_putchar_fd(*str, fd);
		str++;
	}
	return (count);
}

/* DESCRIPTION:
The strcmp() function lexicographically compares the null-terminated strings s1
and s2.
It return an integer greater than, equal to, or less than 0, according as the
string s1 is greater than, equal to, or less than the string s2.
The comparison is done using unsigned characters.
---------------------------------------------------------------------------- */
int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (*(s1 + i) && *(s2 + i) && *(s1 + i) == *(s2 + i))
		i++;
	return ((unsigned char)(*(s1 + i)) - (unsigned char)(*(s2 + i)));
}

/* DESCRIPTION:
Exits the program, outputting a string with the details on the error to STDOUT.
If str is "errno" the default description of error is displayed. Else, the
custom str will be used as description of the error.
---------------------------------------------------------------------------- */
void	*ft_print_error(char *str)
{
	ft_putstr_fd("\033[31mError: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\033[0;39m", 2);
	return (NULL);
}
