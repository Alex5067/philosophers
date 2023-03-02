/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarrus <sjarrus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:45:17 by igoraleksee       #+#    #+#             */
/*   Updated: 2022/04/23 10:22:43 by sjarrus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/errno.h>
# include <stdlib.h>

typedef struct s_mutex
{
	pthread_mutex_t	*mutex;
	pthread_mutex_t	talk;
}	t_mutex;

typedef struct s_arg
{
	int			num_of_ph;
	long long	time_to_die;
	long long	time_to_eat;
	long long	time_to_sleep;
	int long	num_of_ph_eat;
}	t_arg;

typedef struct s_philo
{
	pthread_t		philo;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_mutex			mtx;
	t_arg			args;
	int				eat_count;
	long long		time;
	long long		last_eat;
	unsigned int	i;
	long long		*die;
	int				eat_philo;
}	t_philo;

typedef struct s_all
{
	unsigned int	i;
	long long		*die;
	int				eat_philo;
	int				philo_dead;
	pthread_t		dead;
	t_mutex			mtx;
	t_philo			*philo;
	t_arg			arg;
}	t_all;

void		init_args(t_arg *arg);
long long	get_time(void);
void		philo_sleep(long long time);
int			init_all(t_all *all);
int			init_mutex(t_all *all);
int			create_treads(t_all *all);
int			print_error(char *err);
int			destroy_mutex(t_all *all);
int			pars_args(t_arg *arg, int argc, char **argv);
int			ft_isdigit(int ch);
int			ft_atoi(const char *str);
void		init_struct(t_all *all);
int			fill_args(char **argv, t_arg *arg);

#endif