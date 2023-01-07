/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_init_data_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 23:35:11 by isojo-go          #+#    #+#             */
/*   Updated: 2023/01/07 09:53:03 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	ft_read_args(t_data *data, int argc, char **argv)
{
	data->n_off = ft_atoi(*(argv + 1));
	data->t_die = ft_atoi(*(argv + 2));
	data->t_eat = ft_atoi(*(argv + 3));
	data->t_sleep = ft_atoi(*(argv + 4));
	data->stop = 0;
	if (argc == 6)
		data->max_it = ft_atoi(*(argv + 5));
	else
		data->max_it = -1;
}

static int	ft_alloc_philos(t_data *data)
{
	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->n_off);
	if (data->philos == NULL)
	{
		ft_print_error(MEMALLOC_ERROR);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	ft_alloc_forks(t_data *data)
{
	data->forks = (t_fork *)malloc(sizeof(t_fork) * data->n_off);
	if (data->forks == NULL)
	{
		ft_print_error(MEMALLOC_ERROR);
		free (data->philos);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

t_data	*ft_init(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		return (ft_print_error(MEMALLOC_ERROR));
	ft_read_args(data, argc, argv);
	if (ft_alloc_philos(data) == 1)
	{
		free (data);
		return (NULL);
	}
	if (ft_alloc_forks(data) == 1)
	{
		free (data);
		return (NULL);
	}
	if (pthread_mutex_init(&data->screen, NULL) != 0)
	{
		ft_print_error(MUTEX_ERROR);
		ft_free_all(data);
		return (NULL);
	}
	return (data);
}

void	ft_free_all(t_data *data)
{
	free (data->philos);
	free (data->forks);
	free (data);
}
