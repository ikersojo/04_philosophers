/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_setup_threads.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:52:21 by isojo-go          #+#    #+#             */
/*   Updated: 2023/01/03 22:41:52 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_prepare_the_table(t_data *data)
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
			ft_exit_w_error(MUTEX_ERROR);
	}
}

void	ft_sit_in_the_table(t_data *data)
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
			ft_exit_w_error(TH_NOT_CREATED);
	}
}

void	ft_leave_the_table(t_data *data)
{
	int			i;
	t_philo		*philo;

	i = -1;
	while (++i < data->n_off)
	{
		philo = data->philos + i;
		if (pthread_join(philo->th, NULL) != 0)
			ft_exit_w_error(TH_NOT_JOINED);
	}
}
