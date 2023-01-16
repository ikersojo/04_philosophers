/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_init_data_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 23:35:11 by isojo-go          #+#    #+#             */
/*   Updated: 2023/01/16 20:18:30 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

static void	ft_read_args(t_data *data, int argc, char **argv)
{
	data->n_off = ft_atoi(*(argv + 1));
	data->t_die = ft_atoi(*(argv + 2));
	data->t_eat = ft_atoi(*(argv + 3));
	data->t_sleep = ft_atoi(*(argv + 4));
	data->ready = 0;
	if (argc == 6)
		data->max_it = ft_atoi(*(argv + 5));
	else
		data->max_it = -1;
}

t_data	*ft_init(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		ft_error_exit(MEMALLOC_ERROR);
	ft_read_args(data, argc, argv);
	data->philo = (t_philo *)malloc(sizeof(t_philo) * 1);
	if (data->philo == NULL)
	{
		free (data);
		ft_error_exit(MEMALLOC_ERROR);
	}
	data->pid = (pid_t *)malloc(sizeof(pid_t) * data->n_off);
	if (data->pid == NULL)
	{
		free(data->philo);
		free (data);
		ft_error_exit(MEMALLOC_ERROR);
	}
	sem_unlink("screen");
	data->screen = sem_open("screen", O_CREAT, 0666, 1);
	return (data);
}

void	ft_free_all(t_data *data)
{
	free(data->pid);
	free (data->philo);
	free (data);
}
