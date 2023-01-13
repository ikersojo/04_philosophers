/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_actions_1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:07:35 by isojo-go          #+#    #+#             */
/*   Updated: 2023/01/10 17:48:34 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

// void	ft_take_fork(t_philo *philo, t_fork *fork)
// {
// 	pthread_mutex_lock(&fork->mutex);
// 	fork->status = IN_USE;
// 	fork->holder = philo->id;
// }

// void	ft_leave_fork(t_fork *fork)
// {
// 	fork->status = NOT_IN_USE;
// 	fork->holder = 0;
// 	pthread_mutex_unlock(&fork->mutex);
// }

void	ft_start_eat(t_data *data)
{
	if (data->stop != 1)
		ft_eating(data);
	sem_post(data->forks);
	sem_post(data->forks);
	if (data->stop != 1)
		ft_sleeping(data);
	if (data->stop != 1)
		ft_thinking(data);
}
