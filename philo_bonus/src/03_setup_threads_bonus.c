/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_setup_threads_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:52:21 by isojo-go          #+#    #+#             */
/*   Updated: 2023/01/10 18:01:08 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

int	ft_prepare_the_table(t_data *data)
{
	data->forks = sem_open("forks", O_CREAT, 0666, data->n_off);
	return (EXIT_SUCCESS);
}

int	ft_sit_in_the_table(t_data *data)
{
	int		i;

	data->start = ft_now();
	i = -1;
	while (++i < data->n_off)
	{
		data->pid = fork(); // ver donde va
		if (data->pid == -1)
		{
			ft_free_all(data);
			ft_error_exit(P_NOT_CREATED);
		}
		if (data->pid == 0)
		{
			data->philo->id = i + 1;
			data->philo->it = 0;
			data->philo->status = THINKING;
			launch_thread(data);
		}
	}
	return (EXIT_SUCCESS);
}

// int	ft_leave_the_table(t_data *data)
// {
// 	int			i;
// 	t_philo		*philo;

// 	i = -1;
// 	while (++i < data->n_off)
// 	{
// 		philo = data->philos + i;
// 		if (pthread_join(philo->th, NULL) != 0)
// 		{
// 			ft_print_error(TH_NOT_JOINED);
// 			return (EXIT_FAILURE);
// 		}
// 	}
// 	return (EXIT_SUCCESS);
// }
