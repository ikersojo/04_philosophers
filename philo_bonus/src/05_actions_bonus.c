/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_actions_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:26:18 by isojo-go          #+#    #+#             */
/*   Updated: 2023/01/16 20:23:29 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	ft_start_eat(t_data *data)
{
	ft_eating(data);
	sem_post(data->forks);
	ft_sleeping(data);
	ft_thinking(data);
}

void	ft_eating(t_data *data)
{
	long	time;

	data->philo->status = EATING;
	data->philo->it++;
	if (ft_now() - data->philo->last_meal > data->t_die)
		ft_die(data);
	else
	{
		sem_wait(data->screen);
		time = ft_now() - data->start;
		printf("%ldms %d has taken a fork\n", time, data->philo->id);
		printf("%ldms %d has taken a fork\n", time, data->philo->id);
		printf("%ldms %d is eating\n", time, data->philo->id);
		sem_post(data->screen);
		data->philo->last_meal = ft_now();
		if (data->t_eat > data->t_die)
		{
			ft_enhanced_usleep(data->t_die);
			ft_die(data);
		}
		ft_enhanced_usleep(data->t_eat);
		data->philo->full = ft_now();
	}
}

void	ft_sleeping(t_data *data)
{
	long	time;

	data->philo->status = SLEEPING;
	sem_wait(data->screen);
	time = ft_now() - data->start;
	printf("%ldms %d is sleeping\n", time, data->philo->id);
	sem_post(data->screen);
	if (ft_now() - data->philo->last_meal + data->t_sleep < data->t_die)
		ft_enhanced_usleep(data->t_sleep);
	else
	{
		time = data->t_die - (ft_now() - data->philo->last_meal);
		ft_enhanced_usleep(time);
		ft_die(data);
	}
}

void	ft_thinking(t_data *data)
{
	int	t_think;

	if (data->n_off % 2 != 0)
	{
		if (ft_now() - data->philo->full < data->t_eat * 2 + 1)
			t_think = 1;
		else
			t_think = 0;
		if (ft_now() - data->philo->full < data->t_eat + 1)
			t_think += 1;
	}
	else
		t_think = 1;
	data->philo->status = THINKING;
	sem_wait(data->screen);
	printf("%ldms %d is thinking\n", ft_now() - data->start, data->philo->id);
	sem_post(data->screen);
	ft_enhanced_usleep(t_think);
	if (ft_now() - data->philo->last_meal > data->t_die)
		ft_die(data);
}

void	ft_die(t_data *data)
{
	long	time;

	time = ft_now() - data->start;
	sem_wait(data->screen);
	data->philo->status = DEAD;
	printf("\033[31m%ldms %d has died\033[0;39m\n", time, data->philo->id);
	exit(EXIT_SUCCESS);
}
