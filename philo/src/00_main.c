/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 23:45:54 by isojo-go          #+#    #+#             */
/*   Updated: 2023/01/05 01:12:20 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	int		error_flag;

	error_flag = 0;
	if (ft_check_input(argc, argv) == 1)
		return (EXIT_FAILURE);
	data = ft_init(argc, argv);
	if (data == NULL)
		return (EXIT_FAILURE);
	if (ft_prepare_the_table(data) == 1)
		error_flag = 1;
	if (ft_sit_in_the_table(data) == 1 && error_flag == 0)
		error_flag = 1;
	if (ft_leave_the_table(data) == 1 && error_flag == 0)
		error_flag = 1;
	if (pthread_mutex_destroy(&data->screen) != 0 && error_flag == 0)
		ft_print_error(MUTEX_ERROR);
	ft_free_all(data);
	if (error_flag == 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
