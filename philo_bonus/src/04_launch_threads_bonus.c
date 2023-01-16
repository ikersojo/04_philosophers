/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_launch_threads_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:30:24 by isojo-go          #+#    #+#             */
/*   Updated: 2023/01/16 20:23:29 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	ft_die_alone(t_data *data)
{
	if (data->n_off == 1)
	{
		ft_enhanced_usleep(data->t_die);
		ft_die(data);
	}
}

void	*ft_check_forks(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	sem_wait(data->forks);
	data->ready = 1;
	return (NULL);
}

static void	ft_eatattempt(t_data *data)
{
	pthread_t	th;

	while (data->philo->status == THINKING
		&& (data->philo->it < data->max_it || data->max_it == -1))
	{
		pthread_create(&th, NULL, ft_check_forks, (void *)data);
		pthread_detach(th);
		while (1)
		{
			if (data->ready == 1)
			{
				data->ready = 0;
				ft_start_eat(data);
				break ;
			}
			else
				usleep(500);
			if (ft_now() - data->philo->last_meal > data->t_die)
				ft_die(data);
		}
		if (data->philo->it == data->max_it)
			exit(EXIT_SUCCESS);
	}
}

void	launch_thread(t_data *data)
{
	usleep(250);
	if (data->philo->id % 2 == 0)
		usleep (250);
	ft_die_alone(data);
	data->philo->last_meal = data->start;
	data->philo->full = data->start;
	ft_eatattempt(data);
}
