/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 23:45:54 by isojo-go          #+#    #+#             */
/*   Updated: 2023/01/03 22:48:04 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	ft_check_input(argc, argv);
	data = ft_init(argc, argv);
	ft_prepare_the_table(data);
	ft_sit_in_the_table(data);
	ft_leave_the_table(data);
	if (pthread_mutex_destroy(&data->screen) != 0)
		ft_exit_w_error(MUTEX_ERROR);
	ft_free_all(data);
	return (EXIT_SUCCESS);
}
