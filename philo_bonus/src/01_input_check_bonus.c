/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_input_check_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 22:18:35 by isojo-go          #+#    #+#             */
/*   Updated: 2023/01/10 15:13:02 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

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
	if ((argc != 5 && argc != 6) || ft_empty(argc, argv) || ft_int(argc, argv))
		ft_error_exit(WRONG_SYNTAX);
	if (ft_atoi(*(argv + 1)) == 0 || ft_atoi(*(argv + 2)) == 0 || (argc == 6
			&& ft_atoi(*(argv + 5)) == 0))
		ft_error_exit(WRONG_SCOPE);
	return (EXIT_SUCCESS);
}
