/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igoralekseev <igoralekseev@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:12:14 by igoraleksee       #+#    #+#             */
/*   Updated: 2022/03/10 21:44:35 by igoraleksee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_args(char *arg)
{
	int	i_arg;

	i_arg = ft_atoi(arg);
	if (i_arg <= 0)
		return (-1);
	return (i_arg);
}

int	fill_args(char **argv, t_arg *arg)
{
	arg->num_of_ph = check_args(argv[1]);
	arg->time_to_die = check_args(argv[2]);
	arg->time_to_eat = check_args(argv[3]);
	arg->time_to_sleep = check_args(argv[4]);
	if (argv[5])
		arg->num_of_ph_eat = check_args(argv[5]);
	if (arg->num_of_ph == -1 || arg->time_to_eat == -1
		|| arg->time_to_sleep == -1 || arg->time_to_die == -1
		|| (argv[5] && arg->num_of_ph_eat == -1))
		return (1);
	return (0);
}

int	check_arg_val(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (1);
		else
			i++;
	}
	return (0);
}

int	pars_args(t_arg *arg, int argc, char **argv)
{
	int	i;
	int	num;

	i = 1;
	num = argc;
	init_args(arg);
	while (num > 0)
	{
		while (argv[i])
		{
			if (check_arg_val(argv[i]))
				return (1);
			else
				i++;
		}
		num--;
	}
	if (fill_args(argv, arg))
		return (1);
	return (0);
}
