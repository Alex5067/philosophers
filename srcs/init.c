/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igoralekseev <igoralekseev@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:12:27 by igoraleksee       #+#    #+#             */
/*   Updated: 2022/04/23 14:33:26 by igoraleksee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_args(t_arg *arg)
{
	arg->num_of_ph = 0;
	arg->time_to_eat = 0;
	arg->time_to_sleep = 0;
	arg->time_to_die = 0;
	arg->num_of_ph_eat = -2;
}

void	init_struct(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->arg.num_of_ph)
	{
		all->philo[i].i = i + 1;
		all->philo[i].time = get_time();
		all->philo[i].left_fork = &all->mtx.mutex[i];
		all->philo[i].right_fork = &all->mtx.mutex[(i + 1) \
		% all->arg.num_of_ph];
		all->philo[i].mtx.talk = all->mtx.talk;
		all->philo[i].args = all->arg;
		all->philo[i].die = all->die;
		all->philo[i].last_eat = 0;
		all->philo[i].eat_count = 0;
		all->philo[i].eat_philo = 0;
		i++;
	}
}

int	init_all(t_all *all)
{
	all->i = 0;
	all->eat_philo = 0;
	all->philo_dead = 0;
	all->philo = (t_philo *)malloc(sizeof(t_philo) \
	* all->arg.num_of_ph);
	all->mtx.mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
	* all->arg.num_of_ph);
	if (!all->philo || !all->mtx.mutex)
		return (1);
	return (0);
}

int	init_mutex(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->arg.num_of_ph)
	{
		if (pthread_mutex_init(&(all->mtx.mutex[i]), NULL))
			return (print_error("Error! Pthread_mutex_init failed!\n"));
		i++;
	}
	if (pthread_mutex_init(&(all->mtx.talk), NULL))
		return (print_error("Error! Pthread_mutex_init failed!\n"));
	init_struct(all);
	return (0);
}
