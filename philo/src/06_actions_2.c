/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_actions_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:07:35 by isojo-go          #+#    #+#             */
/*   Updated: 2023/01/04 22:49:25 by isojo-go         ###   ########.fr       */
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

void	ft_die(t_data *data, t_philo *philo)
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
	if (data->stop == 0)
	{
		data->stop = 1;
		philo->status = DEAD;
		if (pthread_create(&th, NULL, print_die_th, (void *)info) != 0)
		{
			ft_print_error(TH_NOT_CREATED);
			return ;
		}
		pthread_detach(th);
	}
}
