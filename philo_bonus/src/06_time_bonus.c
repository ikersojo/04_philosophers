/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_time_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:52:26 by isojo-go          #+#    #+#             */
/*   Updated: 2023/01/16 20:23:29 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

long	ft_now(void)
{
	struct timeval	now;
	long			ms;

	gettimeofday(&now, NULL);
	ms = (now.tv_sec * 1000) + (now.tv_usec / 1000);
	return (ms);
}

void	ft_enhanced_usleep(long time)
{
	long	now;

	now = ft_now();
	while (ft_now() < (now + time))
	{
		usleep (500);
	}
}
