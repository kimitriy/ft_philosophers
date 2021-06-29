#include "ft_philosophers.h"

void	priority_node(t_prime *p)
{
	int	i;

	i = 0;
	while (i < p->n_ph)
	{
		if (p->arr_ph[i].have_eatn > p->mntr.n_mls_ate[i])
		{
			change_priority(p);
			
		}
		i++;
	}
}

void	is_dead(t_prime *p)
{

}

void	monitor(t_prime *p)
{
	while (1)
	{
		priority_node(p);
		is_dead(p);
	}
}