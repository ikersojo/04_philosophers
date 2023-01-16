/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 23:45:54 by isojo-go          #+#    #+#             */
/*   Updated: 2023/01/16 18:57:07 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	int		i;

	ft_check_input(argc, argv);
	data = ft_init(argc, argv);
	ft_prepare_the_table(data);
	ft_sit_in_the_table(data);
	if (data->pid != 0)
	{
		waitpid(-1, NULL, 0);
		i = 0;
		while (*(data->pid + i))
			kill(*(data->pid + i++), SIGKILL);
		sem_close(data->screen);
		sem_close(data->forks);
	}
	ft_free_all(data);
	return (EXIT_SUCCESS);
}
