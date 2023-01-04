/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_actions_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:26:18 by isojo-go          #+#    #+#             */
/*   Updated: 2023/01/04 22:49:25 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	ft_eating(t_data *data, t_philo *philo)
{
	pthread_t	th;
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (info == NULL)
	{
		ft_print_error(MEMALLOC_ERROR);
		return ;
	}
	info->data = data;
	info->id = philo->id;
	info->time = ft_now() - data->start;
	if (pthread_create(&th, NULL, print_eat_th, (void *)info) != 0)
	{
		ft_print_error(TH_NOT_CREATED);
		return ;
	}
	pthread_detach(th);
	philo->status = EATING;
	philo->it++;
	if (ft_now() - philo->last_meal < data->t_die)
	{
		philo->last_meal = ft_now();
		usleep(data->t_eat * 1000);
	}
	else
		ft_die(data, philo);
}

static void	ft_sleeping(t_data *data, t_philo *philo)
{
	pthread_t	th;
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (info == NULL)
	{
		ft_print_error(MEMALLOC_ERROR);
		return ;
	}
	info->data = data;
	info->id = philo->id;
	info->time = ft_now() - data->start;
	if (pthread_create(&th, NULL, print_sleep_th, (void *)info) != 0)
	{
		ft_print_error(TH_NOT_CREATED);
		return ;
	}
	pthread_detach(th);
	philo->status = SLEEPING;
	if (ft_now() - philo->last_meal + data->t_sleep < data->t_die)
		usleep(data->t_sleep * 1000);
	else
	{
		usleep((data->t_die - (ft_now() - philo->last_meal)) * 1000);
		ft_die(data, philo);
	}
}

static void	ft_thinking(t_data *data, t_philo *philo)
{
	pthread_t	th;
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (info == NULL)
	{
		ft_print_error(MEMALLOC_ERROR);
		return ;
	}
	info->data = data;
	info->id = philo->id;
	info->time = ft_now() - data->start;
	if (pthread_create(&th, NULL, print_think_th, (void *)info) != 0)
	{
		ft_print_error(TH_NOT_CREATED);
		return ;
	}
	pthread_detach(th);
	philo->status = THINKING;
	if (data->n_off % 2 != 0)
		usleep(data->t_eat * 1000 + 1000);
}

void	ft_start_eat(t_data *data, t_philo *philo, t_fork *fk_r, t_fork *fk_l)
{
	if (data->stop != 1)
		ft_eating(data, philo);
	ft_leave_fork(fk_r);
	ft_leave_fork(fk_l);
	if (data->stop != 1)
		ft_sleeping(data, philo);
	if (data->stop != 1)
		ft_thinking(data, philo);
}
