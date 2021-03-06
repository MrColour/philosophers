/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinu <xinu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 23:11:09 by xinu              #+#    #+#             */
/*   Updated: 2020/04/24 00:54:51 by xinu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	eto_ad(int event, char *dest)
{
	size_t	len;

	if (event == E_FORK)
		len = at_strncpy(dest, " has taken a fork\n", 18);
	else if (event == E_EATS)
		len = at_strncpy(dest, " is eating\n", 11);
	else if (event == E_SLEE)
		len = at_strncpy(dest, " is sleeping\n", 13);
	else if (event == E_THIN)
		len = at_strncpy(dest, ANSI_RESET" is thinking\n", 18);
	else if (event == E_DIED)
		len = at_strncpy(dest, " died\n", 5);
	else
		len = at_strncpy(dest, " ["RED"ERROR"ANSI_RESET"]!\n", 19);
	return (len);
}

int		color_output(int id, char *dest)
{
	int	result;

	result = 0;
	if (id == 0)
		result = at_strncpy(dest, CYAN, sizeof(CYAN));
	else if (id == 1)
		result = at_strncpy(dest, PURPLE, sizeof(PURPLE));
	else if (id == 2)
		result = at_strncpy(dest, BLUE, sizeof(BLUE));
	else if (id == 3)
		result = at_strncpy(dest, MAGENTA, sizeof(MAGENTA));
	else if (id == 4)
		result = at_strncpy(dest, LIGHT_PURPLE, sizeof(LIGHT_PURPLE));
	return (result);
}

void	philo_announce(int event_type, int philo_id)
{
	size_t			at;
	char			buff[100];
	long long		milli_sec;
	struct timeval	curr_time;

	gettimeofday(&curr_time, NULL);
	milli_sec = tvto_millisec(&curr_time);

	at = color_output(philo_id, &buff[0]);
	at += llto_ad(milli_sec, &buff[at]);
	buff[at++] = ' ';
	at += llto_ad(philo_id, &buff[at]);
	at += eto_ad(event_type, &buff[at]);

	write(1, buff, at);
}
