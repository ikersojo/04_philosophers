/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_launch_threads_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:30:24 by isojo-go          #+#    #+#             */
/*   Updated: 2023/01/10 18:01:49 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

// static t_philo	*ft_get_philo(t_data *data)
// {
// 	pthread_t	tid;
// 	t_philo		*philo;
// 	int			i;

// 	tid = pthread_self();
// 	i = -1;
// 	while (++i < data->n_off)
// 	{
// 		philo = data->philos + i;
// 		if (philo->th == tid)
// 			return (philo);
// 	}
// 	ft_print_error(TH_ID_NOT_FOUND);
// 	return (NULL);
// }

// static t_fork	*ft_get_fork(t_data *data, int id)
// {
// 	int		i;
// 	t_fork	*fork;

// 	i = -1;
// 	while (++i < data->n_off)
// 	{
// 		fork = data->forks + i;
// 		if (fork->id == id)
// 			return (fork);
// 	}
// 	ft_print_error(FORK_ID_NOT_FOUND);
// 	return (NULL);
// }

void	ft_die_alone(t_data *data)
{
	if (data->stop == 1)
		exit (EXIT_SUCCESS);
	if (data->n_off == 1)
	{
		ft_enhanced_usleep(data, data->t_die);
		ft_die(data);
		exit (EXIT_FAILURE); //sobra
	}
}

static void	ft_eatattempt(t_data *data)
{
	int	fork_r;
	int	fork_l;

	fork_r = sem_wait(data->forks);
	fork_l = sem_wait(data->forks);
	if (fork_r == 0 && fork_l == 0)
		ft_start_eat(data);
	else
	{
		if (fork_r != 0)
			sem_post(data->forks);
		if (fork_l != 0)
			sem_post(data->forks);
		usleep(500);
	}
	if (ft_now() - data->philo->last_meal > data->t_die)
		ft_die(data);
}

void	launch_thread(t_data *data)
{
	usleep(250);
	if (data->philo->id % 2 == 0)
		usleep (250);
	ft_die_alone(data);
	data->philo->last_meal = data->start;
	data->philo->full = data->start;
	while (data->philo->status == THINKING && data->stop != 1
		&& (data->philo->it < data->max_it || data->max_it == -1))
		ft_eatattempt(data);
	return ;
}
