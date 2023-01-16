/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 23:44:54 by isojo-go          #+#    #+#             */
/*   Updated: 2023/01/16 20:23:29 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <semaphore.h>
# include <sys/wait.h>
# include <signal.h>

// Error Messages
# define WRONG_SYNTAX	"Wrong Syntax. \
Please use the following:\n\n\
    ./philo arg1 arg2 arg3 arg4 (arg5)\n\
      <arg1> number_of_philosophers\n\
      <arg2> time_to_die\n\
      <arg3> time_to_eat\n\
      <arg4> time_to_sleep\n\
      <arg5> (optional) number_of_times_each_philosopher_must_eat\n\
    *all args to be defined as positive integers\n\n"

# define WRONG_SCOPE	"Wrong Scope. \
Please check input considering the following:\n\n\
    - the number_of_philosophers (arg1) must be at least 1 \
(in order to be able to eat, at least 2 are required).\n\
    - if the time_to_die (arg2) is 0, all will instantly die.\n\
    - if number_of_times_each_philosopher_must_eat (arg5) is 0 the \
simulation will instantly stop.\n\n"

# define MEMALLOC_ERROR		"Memory could not be allocated.\n"
# define P_NOT_CREATED		"Process could not be created.\n"
# define P_ID_NOT_FOUND		"Process id not found\n"
# define SEM_ERROR			"Semaphore could not be created/destroyed.\n"

// Potential Philosophers Conditions
# define EATING			0
# define SLEEPING		1
# define THINKING		2
# define DEAD			3

// STRUCTS
typedef struct s_philo
{
	int			id;
	int			status;
	int			it;
	long		last_meal;
	long		full;
}				t_philo;

typedef struct s_data
{
	int				n_off;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				max_it;
	long			start;
	int				ready;
	t_philo			*philo;
	pid_t			*pid;
	sem_t			*screen;
	sem_t			*forks;
}					t_data;

// FUNCTIONS
/*------ INITIALIZE AND DESTROY DATA STRUCTURE ------*/
t_data	*ft_init(int argc, char **argv);
void	ft_free_all(t_data *data);

/*------ CHECK VALIDITY OF USER INPUT ------*/
int		ft_check_input(int argc, char **argv);

/*------ SETUP/DESTROY THE THREADS AND MUTEXES ------*/
void	ft_prepare_the_table(t_data *data);
void	ft_sit_in_the_table(t_data *data);

/*------ PHILOSOPHERS ACTIONS ------*/
void	launch_thread(t_data *data);
void	ft_start_eat(t_data *data);
void	ft_eating(t_data *data);
void	ft_sleeping(t_data *data);
void	ft_thinking(t_data *data);
void	ft_die(t_data *data);

/*------ TIME RELATED FUNCTIONS ------*/
long	ft_now(void);
void	ft_enhanced_usleep(long time);

/*------ EXTRACTS FROM LIBFT ------*/
int		ft_isspace(int c);
int		ft_isdigit(int c);
int		ft_isint(char *s);
int		ft_atoi(const char *str);
int		ft_putchar_fd(int c, int fd);
int		ft_putstr_fd(char *str, int fd);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_error_exit(char *str);

#endif
