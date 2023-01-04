/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_setup_threads.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:52:21 by isojo-go          #+#    #+#             */
/*   Updated: 2023/01/04 22:49:25 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_prepare_the_table(t_data *data)
{
	t_fork	*fork;
	int		i;

	i = -1;
	while (++i < data->n_off)
	{
		fork = data->forks + i;
		fork->id = i + 1;
		fork->status = NOT_IN_USE;
		fork->holder = 0;
		if (pthread_mutex_init(&fork->mutex, NULL) != 0)
		{
			ft_print_error(MUTEX_ERROR);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	ft_sit_in_the_table(t_data *data)
{
	int		i;
	t_philo	*philo;

	data->start = ft_now();
	i = -1;
	while (++i < data->n_off)
	{
		philo = data->philos + i;
		philo->id = i + 1;
		philo->it = 0;
		philo->status = THINKING;
		philo->last_meal = ft_now();
		if (pthread_create(&philo->th, NULL, launch_thread, (void *)data) != 0)
		{
			ft_print_error(TH_NOT_CREATED);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	ft_leave_the_table(t_data *data)
{
	int			i;
	t_philo		*philo;

	i = -1;
	while (++i < data->n_off)
	{
		philo = data->philos + i;
		if (pthread_join(philo->th, NULL) != 0)
		{
			ft_print_error(TH_NOT_JOINED);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
