/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_actions_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:26:18 by isojo-go          #+#    #+#             */
/*   Updated: 2023/01/05 01:48:47 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_eating(t_data *data, t_philo *philo)
{
	philo->status = EATING;
	philo->it++;
	if (ft_now() - philo->last_meal > data->t_die)
		ft_die(data, philo);
	else
	{
		pthread_mutex_lock(&data->screen);
		printf("%ldms %d has taken a fork\n", ft_now() - data->start, philo->id);
		printf("%ldms %d is eating\n", ft_now() - data->start, philo->id);
		pthread_mutex_unlock(&data->screen);
		philo->last_meal = ft_now();
		ft_enhanced_usleep(data->t_eat);
	}
}

void	ft_sleeping(t_data *data, t_philo *philo)
{
	philo->status = SLEEPING;
	pthread_mutex_lock(&data->screen);
	printf("%ldms %d is sleeping\n", ft_now() - data->start, philo->id);
	pthread_mutex_unlock(&data->screen);
	if (ft_now() - philo->last_meal + data->t_sleep < data->t_die)
		ft_enhanced_usleep(data->t_sleep);
	else
	{
		ft_enhanced_usleep(data->t_die - (ft_now() - philo->last_meal));
		ft_die(data, philo);
	}
}

void	ft_thinking(t_data *data, t_philo *philo)
{
	int	t_think;

	t_think = data->t_eat + 1;
	philo->status = THINKING;
	pthread_mutex_lock(&data->screen);
	printf("%ldms %d is thinking\n", ft_now() - data->start, philo->id);
	pthread_mutex_unlock(&data->screen);
	if (ft_now() - philo->last_meal + t_think < data->t_die)
		ft_enhanced_usleep(t_think);
}

void	ft_die(t_data *data, t_philo *philo)
{
	long	time;

	time = ft_now() - data->start;
	if (data->stop == 0)
	{
		data->stop = 1;
		philo->status = DEAD;
		usleep(1000);
		pthread_mutex_lock(&data->screen);
		printf("\033[31m%ldms %d has died\033[0;39m\n", time, philo->id);
		pthread_mutex_unlock(&data->screen);
	}
}
