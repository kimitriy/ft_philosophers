#include "ft_philosophers.h"

void	kill_ph(t_prime *p)
{
	int	i;

	i = 0;
	while (i < p->n_ph)
	{
		pthread_detach(p->ph_ptid[i]);
		i++;
	}
}

int	is_dead(t_prime *p)
{
	int	i;

	i = 0;
	while (i < p->n_ph)
	{
		if ((current_time() - p->arr_ph[i].t_lst_ml)
			* 1000 > (unsigned long)p->t2d)
		{
			prnt_sts(&p->arr_ph[i], "died of hunger");
			kill_ph(p);
			return (1);
		}
		i++;
	}
	return (0);
}

int	is_fed(t_prime *p)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < p->n_ph)
	{
		if (p->arr_ph[i].has_eatn >= p->n_mls_m_eat)
			j++;
		i++;
	}
	if (j == p->n_ph)
	{
		kill_ph(p);
		return (1);
	}	
	else
		return (0);
}

/*
void	print_n_of_meals(t_prime *p)
{
	int		i;

	i = 0;
	while (i < p->n_ph)
	{
		printf("philo[%d] ate %d times\n", i + 1, p->arr_ph[i].has_eatn);
		i++;
	}
}
*/

void	monitor(t_prime *p)
{
	while (1)
	{
		usleep(1000);
		if (is_dead(p) == 1)
			break ;
		if (p->n_mls_m_eat != 0 && is_fed(p) == 1)
			break ;
	}
	return ;
}
