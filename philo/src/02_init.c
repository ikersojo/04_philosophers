/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 23:35:11 by isojo-go          #+#    #+#             */
/*   Updated: 2023/01/02 23:40:47 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_init(int argc, char **argv, t_data *data)
{
	data->n_off = ft_atoi(*(argv + 1));
	data->t_die = ft_atoi(*(argv + 2));
	data->t_eat = ft_atoi(*(argv + 3));
	data->t_sleep = ft_atoi(*(argv + 4));
	if (argc == 6)
		data->max_it = ft_atoi(*(argv + 5));
	else
		data->max_it = -1;
}