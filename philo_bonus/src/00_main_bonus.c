/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 23:45:54 by isojo-go          #+#    #+#             */
/*   Updated: 2023/01/10 18:00:51 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	ft_check_input(argc, argv);
	data = ft_init(argc, argv);
	if (data == NULL)
		return (EXIT_FAILURE);
	ft_prepare_the_table(data);
	ft_sit_in_the_table(data);
	// if (ft_leave_the_table(data) == 1 && error_flag == 0)
	// 	error_flag = 1;
	// if (pthread_mutex_destroy(&data->screen) != 0 && error_flag == 0) // replace with semaphore destry
	if (data->pid != 0)
	{
		waitpid(data->pid, NULL, 0);
		sem_close(data->screen);
		sem_close(data->forks);

	}
	ft_free_all(data);
	return (EXIT_SUCCESS);
}
