/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 23:45:54 by isojo-go          #+#    #+#             */
/*   Updated: 2023/01/02 23:48:26 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"



int	main(int argc, char **argv)
{
	t_data		data;
	// pthread_t	th;


	ft_check_input(argc, argv);
	ft_printf("%sInputs Syantax OK!\n%s", GREEN, DEF_COLOR); // DEBUG

	ft_init(argc, argv, &data);
	ft_printf("captured variables:\n   noff = %d\n  t_die = %d\n  t_eat = %d\nt_sleep = %d\nmax_it = %d\n\n", data.n_off, data.t_die, data.t_eat, data.t_sleep, data.max_it); // DEBUG
	

	// pthread_create(th, NULL, )


	return (EXIT_SUCCESS);
}