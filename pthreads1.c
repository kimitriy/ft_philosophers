#include "ft_philosophers.h"

unsigned long	current_time(void)
{
	static struct timeval	time;

	gettimeofday(&time, NULL);
	return (((time.tv_sec % 1000) * 1000) + (time.tv_usec / 1000));
}

void	prnt_sts(t_phlsphr *ph, char *status)
{
	unsigned long	t_stmp;

	t_stmp = current_time() - ph->t_strt;
	printf("%lu %d %s\n", t_stmp, ph->indx + 1, status);
}

/*
void	wait_for(int intrvl)
{
	unsigned long	stop_wait;

	if (intrvl < 1000000)
		usleep(intrvl);
	else
	{
		stop_wait = current_time() + intrvl;
		while (1)
		{
			if (current_time() >= stop_wait)
				break;
			usleep(100);
		}
	}
}
*/

void	get_frks(t_phlsphr *ph)
{
	pthread_mutex_lock(ph->lfrk);
	pthread_mutex_lock(ph->rfrk);
	ph->t_lst_ml = current_time();
	ph->has_eatn++;
	prnt_sts(ph, "has taken forks");
}

void	release_frks(t_phlsphr *ph)
{
	pthread_mutex_unlock(ph->lfrk);
	pthread_mutex_unlock(ph->rfrk);
}

void	*ph_lives(void *ph1)
{
	t_phlsphr	*ph;

	ph = (t_phlsphr *)ph1;
	ph->t_strt = current_time();
	ph->t_lst_ml = ph->t_strt;
	while (1)
	{
		get_frks(ph);
		prnt_sts(ph, "is eating");
		usleep(*ph->t2e);
		release_frks(ph);
		prnt_sts(ph, "is sleeping");
		usleep(*ph->t2s);
		prnt_sts(ph, "is thinking");
	}
	return (NULL);
}
