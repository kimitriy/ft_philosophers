#include "ft_philosophers.h"

unsigned long	current_time(void)
{
	static struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	prnt_sts(t_phlsphr *ph, char *status)
{
	unsigned int	t_stmp;

	t_stmp = current_time() - ph->t_strt;
	pthread_mutex_lock(ph->p_mtx);
	// ft_putnbr(t_stmp);
	// write(1, " ", 1);
	// ft_putnbr(ph->indx + 1);
	// write(1, " ", 1);
	// write(1, status, ft_strlen(status));
	// write(1, "\n", 1);
	printf("%d %d %s\n", t_stmp, ph->indx + 1, status);
	pthread_mutex_unlock(ph->p_mtx);
}

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

void	get_frks(t_phlsphr *ph)
{
	pthread_mutex_lock(ph->lfrk);
	pthread_mutex_lock(ph->rfrk);
	prnt_sts(ph, "has taken the left fork");
	prnt_sts(ph, "has taken the right fork");
	prnt_sts(ph, "is eating");
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
		ph->t_lst_ml = current_time();
		ph->has_eatn++;
		wait_for(*ph->t2e * 1000);
		release_frks(ph);
		prnt_sts(ph, "is sleeping");
		wait_for(*ph->t2s * 1000);
		prnt_sts(ph, "is thinking");
	}
	return (NULL);
}

void	launch_threads(t_prime *p)
{
	int			i;

	p->dly = 50;
	p->ph_ptid = (pthread_t *)ft_calloc(p->n_ph, sizeof(pthread_t)); //allocates memory to the array of ph_ptid
	
	i = 0;
	while (i < p->n_ph && i != p->n_ph - 1) //odd
	{
		if (pthread_create(&p->ph_ptid[i], NULL, ph_lives, (void *)&p->arr_ph[i]))
			err_message("Thread was not created");
		i += 2;
	}
	wait_for(p->dly * 1000);
	i = 1;
	while (i < p->n_ph) //even
	{
		if (pthread_create(&p->ph_ptid[i], NULL, ph_lives, (void *)&p->arr_ph[i]))
			err_message("Thread was not created");
		i += 2;
	}
	if (p->n_ph % 2 != 0) //last odd
	{
		wait_for(p->dly * 1000);
		if (pthread_create(&p->ph_ptid[p->n_ph - 1], NULL, ph_lives, (void *)&p->arr_ph[p->n_ph - 1]))
			err_message("Thread was not created");
	}
}
