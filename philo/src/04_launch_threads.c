/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_launch_threads.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:30:24 by isojo-go          #+#    #+#             */
/*   Updated: 2023/01/03 23:28:32 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static t_philo	*ft_get_philo(t_data *data)
{
	pthread_t	tid;
	t_philo		*philo;
	int			i;

	tid = pthread_self();
	i = -1;
	while (++i < data->n_off)
	{
		philo = data->philos + i;
		if (philo->th == tid)
			return (philo);
	}
	ft_exit_w_error(TH_ID_NOT_FOUND);
	return (NULL);
}

static t_fork	*ft_get_fork(t_data *data, int id)
{
	int		i;
	t_fork	*fork;

	i = -1;
	while (++i < data->n_off)
	{
		fork = data->forks + i;
		if (fork->id == id)
			return (fork);
	}
	ft_exit_w_error(FORK_ID_NOT_FOUND);
	return (NULL);
}

void	*launch_thread(void *arg)
{
	t_data	*data;
	t_philo	*philo;
	t_fork	*fork_l;
	t_fork	*fork_r;

	data = (t_data *)arg;
	philo = ft_get_philo(data);
	if (data->n_off == 1)
	{
		usleep(data->t_die * 1000);
		philo->status = DEAD;
		pthread_mutex_lock(&data->screen);
		printf("%ldms %d has died\n", ft_now() - data->start, philo->id);
		ft_free_all(data);
		exit(EXIT_SUCCESS);
	}
	fork_r = ft_get_fork(data, philo->id);
	if (philo->id == data->n_off)
		fork_l = ft_get_fork(data, 1);
	else
		fork_l = ft_get_fork(data, philo->id + 1);
	while (philo->status == THINKING && (philo->it < data->max_it || data->max_it == -1))
	{
		if (fork_r->status == NOT_IN_USE)
			ft_take_fork(philo, fork_r);
		if (fork_l->status == NOT_IN_USE)
			ft_take_fork(philo, fork_l);
		if (fork_r->holder == philo->id && fork_l->holder == philo->id)
			ft_eat(data, philo, fork_r, fork_l);
		else if (fork_r->holder == philo->id)
			ft_leave_fork(fork_r);
		else if (fork_l->holder == philo->id)
			ft_leave_fork(fork_l);
		usleep(500); //wait for 0.5ms before trying again
		if (ft_now() - philo->last_meal > data->t_die)
		{
			philo->status = DEAD;
			pthread_mutex_lock(&data->screen);
			printf("%ldms %d has died\n", ft_now() - data->start, philo->id);
			ft_free_all(data);
			exit(EXIT_SUCCESS);
		}
	}
	return (EXIT_SUCCESS);
}
