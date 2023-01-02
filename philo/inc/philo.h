/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 23:44:54 by isojo-go          #+#    #+#             */
/*   Updated: 2023/01/02 23:40:47 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "../lib/LIBFT/inc/libft.h"
# include <pthread.h>
# include <sys/time.h>

//Custom Messages to the user
# define WRONG_SYNTAX	"\033[0;31mWrong Syntax. Please use the following:\n\n\
\t./philo arg1 arg2 arg3 arg4 (arg5)\n\
\t  <arg1> number_of_philosophers\n\
\t  <arg2> time_to_die\n\
\t  <arg3> time_to_eat\n\
\t  <arg4> time_to_sleep\n\
\t  <arg5> (optional) number_of_times_each_philosopher_must_eat\n\
\t*all args to be defined as positive integers\n\n\033[0;39m"


// STRUCTS
typedef struct s_data
{
	int		n_off;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		max_it;
}			t_data;


// typedef struct s_phi
// {
// 	int		th
// }			t_phi;

// FUNCTIONS
void	ft_init(int argc, char **argv, t_data *data);

int		ft_check_input(int argc, char **argv);

// todos los tiempos con los que vamos a trabajar son long y en ms.
long	ft_now(void);

#endif
