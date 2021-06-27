#include "ft_philosophers.h"

void	prnt_sts(t_phlsphr *ph, char *status)
{
	unsigned long	t_stmp;
	pthread_mutex_t	prnt;

	t_stmp = current_time() - ph->t_strt;
	pthread_mutex_lock(ph->p_mtx);
	printf("%lu %d %s\n", t_stmp, ph->indx, status);
	if (!ph->alive)
		pthread_mutex_unlock(ph->p_mtx);
}

void	wait_for(int intrvl)
{
	unsigned long	stop_wait;

	stop_wait = current_time() + intrvl;
	while (1)
	{
		if (current_time() >= stop_wait)
			break;
		usleep(1);
	}
}

int		check_frks(t_phlsphr *ph)
{
	if (ph->lf_f == 1 && ph->rf_f == 1)
		return (1);
	else
		return (0);
}

void	get_frks(t_phlsphr *ph)
{
	pthread_mutex_lock(ph->lf_mtx);
	pthread_mutex_lock(ph->rf_mtx);
	ph->lf_f = 0;
	ph->rf_f = 0;
	prnt_sts(ph, "has taken the left fork");
	prnt_sts(ph, "has taken the right fork");
}

void	release_frks(t_phlsphr *ph)
{
	pthread_mutex_unlock(ph->lf_mtx);
	pthread_mutex_unlock(ph->rf_mtx);
	ph->lf_f = 1;
	ph->rf_f = 1;
}

void	ph_lives(t_phlsphr *ph)
{
	ph->t_strt = current_time();
	while (1)
	{
		if (check_frks(ph) == 1)
		{	
			get_forks(ph);
			prnt_sts(ph, "is eating");
			ph->t_lst_ml = current_time();
			wait_for(*ph->t2e);
			release_frks(ph);
		}
		else
			wait_for(ph->pr);
	}
}

void	launch_threads(t_prime *p)
{
	int	i;

	i = 0;
	pthread_create(p->ph_thread[i], NULL, (void *)monitor, p);
	while (i < p->n_ph)
	{
		pthread_create(p->ph_thread[i], NULL, (void *)ph_lives, &p->arr_ph[i]);
		i++;
	}
	
}