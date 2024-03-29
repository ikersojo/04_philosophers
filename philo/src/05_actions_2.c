/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_actions_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:26:18 by isojo-go          #+#    #+#             */
/*   Updated: 2023/01/13 19:57:35 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_eating(t_data *data, t_philo *philo)
{
	long	time;

	philo->status = EATING;
	philo->it++;
	if (ft_now() - philo->last_meal > data->t_die)
		ft_die(data, philo);
	else
	{
		pthread_mutex_lock(&data->screen);
		if (data->stop == 0)
		{
			time = ft_now() - data->start;
			printf("%ldms %d has taken a fork\n", time, philo->id);
			printf("%ldms %d has taken a fork\n", time, philo->id);
			printf("%ldms %d is eating\n", ft_now() - data->start, philo->id);
		}
		pthread_mutex_unlock(&data->screen);
		philo->last_meal = ft_now();
		ft_enhanced_usleep(data, data->t_eat);
		philo->full = ft_now();
	}
}

void	ft_sleeping(t_data *data, t_philo *philo)
{
	philo->status = SLEEPING;
	pthread_mutex_lock(&data->screen);
	if (data->stop == 0)
		printf("%ldms %d is sleeping\n", ft_now() - data->start, philo->id);
	pthread_mutex_unlock(&data->screen);
	if (ft_now() - philo->last_meal + data->t_sleep < data->t_die)
		ft_enhanced_usleep(data, data->t_sleep);
	else
	{
		ft_enhanced_usleep(data, data->t_die - (ft_now() - philo->last_meal));
		ft_die(data, philo);
	}
}

void	ft_thinking(t_data *data, t_philo *philo)
{
	int	t_think;

	if (data->n_off % 2 != 0)
	{
		if (ft_now() - philo->full < data->t_eat * 2 + 1)
			t_think = 1;
		else
			t_think = 0;
		if (ft_now() - philo->full < data->t_eat + 1)
			t_think += 1;
	}
	else
		t_think = 1;
	philo->status = THINKING;
	pthread_mutex_lock(&data->screen);
	if (data->stop == 0)
		printf("%ldms %d is thinking\n", ft_now() - data->start, philo->id);
	pthread_mutex_unlock(&data->screen);
	ft_enhanced_usleep(data, t_think);
	if (ft_now() - philo->last_meal > data->t_die)
		ft_die(data, philo);
}

void	ft_die(t_data *data, t_philo *philo)
{
	long	time;

	time = ft_now() - data->start;
	pthread_mutex_lock(&data->screen);
	if (data->stop == 0)
	{
		data->stop = 1;
		philo->status = DEAD;
		printf("\033[31m%ldms %d has died\033[0;39m\n", time, philo->id);
	}
	pthread_mutex_unlock(&data->screen);
}
