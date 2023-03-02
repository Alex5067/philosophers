/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarrus <sjarrus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:12:07 by igoraleksee       #+#    #+#             */
/*   Updated: 2022/04/23 11:41:50 by sjarrus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	destroy_mutex(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->arg.num_of_ph)
	{
		pthread_mutex_destroy(&(all->mtx.mutex[i]));
		pthread_detach(all->philo[i].philo);
		i++;
	}
	if (all->philo_dead)
		pthread_mutex_unlock(&(all->mtx.talk));
	free(all->philo);
	free(all->mtx.mutex);
	return (0);
}

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	dead_checker(t_all *all, int i)
{
	long long	cur_time;

	cur_time = get_time() - all->philo[i].time;
	if (cur_time - all->philo[i].last_eat > all->arg.time_to_die)
	{
		pthread_mutex_lock(&(all->philo[i].mtx.talk));
		printf("%lld %d died!\n", cur_time, all->philo[i].i);
		all->philo_dead = 1;
		return (1);
	}
	return (0);
}

void	*dead(void *arg)
{
	t_all	*all;
	int		i;

	all = (t_all *)arg;
	while (1)
	{
		i = 0;
		while (i < all->arg.num_of_ph)
		{
			if (all->philo[i].eat_count == all->arg.num_of_ph_eat && \
			!all->philo[i].eat_philo)
			{
				all->philo[i].eat_philo = 1;
				all->eat_philo++;
			}
			if (dead_checker(all, i))
				return (0);
			i++;
		}
		if (all->eat_philo == all->arg.num_of_ph)
			break ;
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_all		all;
	int			i;

	i = 0;
	if ((argc != 5 && argc != 6) || pars_args(&all.arg, argc, argv))
		return (print_error("Error! Invalid arguments!\n"));
	if (init_all(&all) || init_mutex(&all))
		return (print_error("Error! Memory allocation error!\n"));
	pthread_create(&all.dead, NULL, dead, &all);
	if (create_treads(&all))
		return (print_error("Error! Threads not created!\n"));
	destroy_mutex(&all);
	return (0);
}
