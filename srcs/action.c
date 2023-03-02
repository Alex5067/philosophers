/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjarrus <sjarrus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:12:33 by igoraleksee       #+#    #+#             */
/*   Updated: 2022/04/23 11:37:38 by sjarrus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eating(t_philo *philo)
{
	long long	time;

	if (philo->args.num_of_ph == 1)
		printf("%lld %d has taken a fork\n", \
		get_time() - philo->time, philo->i);
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	time = get_time() - philo->time;
	pthread_mutex_lock(&(philo->mtx.talk));
	printf("%lld %d has taken a fork\n", time, philo->i);
	printf("%lld %d has taken a fork\n", time, philo->i);
	printf("%lld %d is eating\n", time, philo->i);
	philo->last_eat = get_time() - philo->time;
	pthread_mutex_unlock(&(philo->mtx.talk));
	philo_sleep(philo->args.time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	philo->eat_count++;
}

void	sleeping(t_philo *philo)
{
	long long	time;

	time = get_time() - philo->time;
	pthread_mutex_lock(&(philo->mtx.talk));
	printf("%lld %d is sleeping\n", time, philo->i);
	pthread_mutex_unlock(&(philo->mtx.talk));
	philo_sleep(philo->args.time_to_sleep);
}

void	thinking(t_philo *philo)
{
	long long	time;

	time = get_time() - philo->time;
	pthread_mutex_lock(&(philo->mtx.talk));
	printf("%lld %d is thinking\n", time, philo->i);
	pthread_mutex_unlock(&(philo->mtx.talk));
}

void	*life_cycle(void *arg)
{
	t_philo	*ph;
	int		i;

	i = 0;
	ph = (t_philo *)arg;
	if (ph->i % 2 == 0)
		usleep(100);
	while (ph->args.num_of_ph_eat == -2 || \
	(ph->args.num_of_ph_eat > 0 && i < ph->args.num_of_ph_eat))
	{
		eating(ph);
		sleeping(ph);
		thinking(ph);
		i++;
	}
	return (0);
}

int	create_treads(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->arg.num_of_ph)
	{
		if (pthread_create(&all->philo[i].philo, NULL, \
		life_cycle, (void *)&all->philo[i]))
			return (1);
		i++;
	}
	pthread_join(all->dead, NULL);
	return (0);
}
