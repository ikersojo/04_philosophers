/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_setup_stdout_thread.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:14:39 by isojo-go          #+#    #+#             */
/*   Updated: 2023/01/04 22:49:25 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*print_die_th(void *arg)
{
	t_info	*info;

	info = (t_info *)arg;
	pthread_mutex_lock(&info->data->screen);
	printf("\033[31m%ldms %d has died\033[0;39m\n", info->time, info->id);
	pthread_mutex_unlock(&info->data->screen);
	free (info);
	return (EXIT_SUCCESS);
}

void	*print_eat_th(void *arg)
{
	t_info	*info;

	info = (t_info *)arg;
	pthread_mutex_lock(&info->data->screen);
	printf("%ldms %d has taken a fork\n", info->time, info->id);
	printf("%ldms %d is eating\n", info->time, info->id);
	pthread_mutex_unlock(&info->data->screen);
	free (info);
	return (EXIT_SUCCESS);
}

void	*print_sleep_th(void *arg)
{
	t_info	*info;

	info = (t_info *)arg;
	pthread_mutex_lock(&info->data->screen);
	printf("%ldms %d is sleeping\n", info->time, info->id);
	pthread_mutex_unlock(&info->data->screen);
	free (info);
	return (EXIT_SUCCESS);
}

void	*print_think_th(void *arg)
{
	t_info	*info;

	info = (t_info *)arg;
	pthread_mutex_lock(&info->data->screen);
	printf("%ldms %d is thinking\n", info->time, info->id);
	pthread_mutex_unlock(&info->data->screen);
	free (info);
	return (EXIT_SUCCESS);
}