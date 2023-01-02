/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_input_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 22:18:35 by isojo-go          #+#    #+#             */
/*   Updated: 2023/01/02 23:22:26 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	ft_empty(int argc, char **argv)
{
	int	i;

	i = -1;
	while (++i < argc)
	{
		if (ft_strcmp(*(argv + i), "") == 0)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	ft_int(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (!ft_isint(*(argv + i)) || ft_atoi(*(argv + i)) < 0)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ft_check_input(int argc, char **argv)
{
	(void)argv;
	if ((argc != 5 && argc != 6) || ft_empty(argc, argv) || ft_int(argc, argv))
		ft_exit_w_error(WRONG_SYNTAX);
	return (EXIT_SUCCESS);
}
