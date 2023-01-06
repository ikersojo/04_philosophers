/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_launch_threads.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:30:24 by isojo-go          #+#    #+#             */
/*   Updated: 2023/01/05 01:54:44 by isojo-go         ###   ########.fr       */
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
	ft_print_error(TH_ID_NOT_FOUND);
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
	ft_print_error(FORK_ID_NOT_FOUND);
	return (NULL);
}

static int	ft_die_alone(t_data *data, t_philo *philo)
{
	if (data->stop == 1)
		return (EXIT_FAILURE);
	if (data->n_off == 1)
	{
		ft_enhanced_usleep(data->t_die);
		ft_die(data, philo);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	ft_eatattempt(t_data *data, t_philo *philo, t_fork *fk_r, t_fork *fk_l)
{
	if (fk_r->status == NOT_IN_USE)
		ft_take_fork(philo, fk_r);
	if (fk_l->status == NOT_IN_USE)
		ft_take_fork(philo, fk_l);
	if (fk_r->holder == philo->id && fk_l->holder == philo->id)
		ft_start_eat(data, philo, fk_r, fk_l);
	else
	{
		if (fk_r->holder == philo->id)
			ft_leave_fork(fk_r);
		if (fk_l->holder == philo->id)
			ft_leave_fork(fk_l);
		usleep(500);
	}
}

void	*launch_thread(void *arg)
{
	t_data	*data;
	t_philo	*philo;
	t_fork	*fork_l;
	t_fork	*fork_r;

	data = (t_data *)arg;
	usleep(250);
	philo = ft_get_philo(data);
	if (ft_die_alone(data, philo) == 1)
		return (EXIT_SUCCESS);
	fork_r = ft_get_fork(data, philo->id);
	if (philo->id == data->n_off)
		fork_l = ft_get_fork(data, 1);
	else
		fork_l = ft_get_fork(data, philo->id + 1);
	philo->last_meal = ft_now();
	while (philo->status == THINKING && data->stop != 1
		&& (philo->it < data->max_it || data->max_it == -1))
	{
		ft_eatattempt(data, philo, fork_r, fork_l);
		if (ft_now() - philo->last_meal > data->t_die)
			ft_die(data, philo);
	}
	return (EXIT_SUCCESS);
}
