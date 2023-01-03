/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:26:18 by isojo-go          #+#    #+#             */
/*   Updated: 2023/01/03 22:48:04 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_take_fork(t_philo *philo, t_fork *fork)
{
	pthread_mutex_lock(&fork->mutex);
	fork->status = IN_USE;
	fork->holder = philo->id;
}

void	ft_leave_fork(t_fork *fork)
{
	fork->status = NOT_IN_USE;
	fork->holder = 0;
	pthread_mutex_unlock(&fork->mutex);
}

void	ft_eat(t_data *data, t_philo *philo, t_fork *fork_r, t_fork *fork_l)
{
	philo->status = EATING;
	philo->it++;
	pthread_mutex_lock(&data->screen);
	printf("%ldms %d has taken a fork\n", ft_now() - data->start, philo->id);
	printf("%ldms %d is eating\n", ft_now() - data->start, philo->id);
	pthread_mutex_unlock(&data->screen);
	if(ft_now() - philo->last_meal + data->t_eat < data->t_die)
	{
		philo->last_meal = ft_now();
		usleep(data->t_eat * 1000);
	}
	else
	{
		usleep(data->t_die - (ft_now() - philo->last_meal));
		pthread_mutex_lock(&data->screen);
		printf("%ldms %d has died\n", ft_now() - data->start, philo->id);
		ft_free_all(data);
		exit(EXIT_SUCCESS);
	}
	fork_r->status = NOT_IN_USE;
	fork_r->holder = 0;
	fork_l->status = NOT_IN_USE;
	fork_l->holder = 0;
	pthread_mutex_unlock(&fork_l->mutex);
	pthread_mutex_unlock(&fork_r->mutex);
	philo->status = SLEEPING;
	pthread_mutex_lock(&data->screen);
	printf("%ldms %d is sleeping\n", ft_now() - data->start, philo->id);
	pthread_mutex_unlock(&data->screen);
	if(ft_now() - philo->last_meal + data->t_sleep < data->t_die)
	{
		philo->last_meal = ft_now();
		usleep(data->t_sleep * 1000);
	}
	else
	{
		usleep(data->t_die - (ft_now() - philo->last_meal));
		pthread_mutex_lock(&data->screen);
		printf("%ldms %d has died\n", ft_now() - data->start, philo->id);
		ft_free_all(data);
		exit(EXIT_SUCCESS);
	}
	philo->status = THINKING;
	pthread_mutex_lock(&data->screen);
	printf("%ldms %d is thinking\n", ft_now() - data->start, philo->id);
	pthread_mutex_unlock(&data->screen);
}