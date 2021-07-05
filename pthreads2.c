#include "ft_philosophers.h"

void	pthread_start(t_prime *p, int i)
{
	if (pthread_create(&p->ph_ptid[i], NULL, \
		ph_lives, (void *)&p->arr_ph[i]))
		err_message("Thread was not created");
}

void	launch_threads(t_prime *p)
{
	int	i;

	p->ph_ptid = (pthread_t *)ft_calloc(p->n_ph, sizeof(pthread_t));
	i = 0;
	while (i < p->n_ph && i != p->n_ph - 1)
	{
		pthread_start(p, i);
		i += 2;
	}
	usleep(p->t2d / 3);
	i = 1;
	while (i < p->n_ph)
	{
		pthread_start(p, i);
		i += 2;
	}
	if (p->n_ph % 2 != 0)
	{
		usleep(p->t2d / 3);
		if (pthread_create(&p->ph_ptid[p->n_ph - 1], NULL, \
			ph_lives, (void *)&p->arr_ph[p->n_ph - 1]))
			err_message("Thread was not created");
	}
}
