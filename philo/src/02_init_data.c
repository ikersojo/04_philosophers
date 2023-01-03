/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 23:35:11 by isojo-go          #+#    #+#             */
/*   Updated: 2023/01/03 22:48:04 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

t_data	*ft_init(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		ft_exit_w_error(MEMALLOC_ERROR);
	data->n_off = ft_atoi(*(argv + 1));
	data->t_die = ft_atoi(*(argv + 2));
	data->t_eat = ft_atoi(*(argv + 3));
	data->t_sleep = ft_atoi(*(argv + 4));
	if (argc == 6)
		data->max_it = ft_atoi(*(argv + 5));
	else
		data->max_it = -1;
	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->n_off);
	if (data->philos == NULL)
		ft_exit_w_error(MEMALLOC_ERROR);
	data->forks = (t_fork *)malloc(sizeof(t_fork) * data->n_off);
	if (data->forks == NULL)
		ft_exit_w_error(MEMALLOC_ERROR);
	if (pthread_mutex_init(&data->screen, NULL) != 0)
		ft_exit_w_error(MUTEX_ERROR);
	return (data);
}

void	ft_free_all(t_data *data)
{
	free (data->philos);
	free (data->forks);
	free (data);
}
