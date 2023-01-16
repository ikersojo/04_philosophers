/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_setup_threads_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:52:21 by isojo-go          #+#    #+#             */
/*   Updated: 2023/01/15 22:06:52 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	ft_prepare_the_table(t_data *data)
{
	int	fork_pairs;

	if (data->n_off % 2 == 0)
		fork_pairs = data->n_off / 2;
	else
		fork_pairs = (data->n_off - 1) / 2;
	sem_unlink("forks");
	data->forks = sem_open("forks", O_CREAT, 0666, fork_pairs);
}

void	ft_sit_in_the_table(t_data *data)
{
	int		i;
	pid_t	pid;

	data->start = ft_now();
	pid = 1;
	i = -1;
	while (++i < data->n_off)
	{
		if (pid > 0)
			pid = fork();
		if (pid == 0)
		{
			data->philo->id = i + 1;
			data->philo->it = 0;
			data->philo->status = THINKING;
			launch_thread(data);
		}
		else
			*(data->pid + i) = pid;
	}
}
