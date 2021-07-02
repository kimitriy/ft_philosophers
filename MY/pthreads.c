#include "ft_philosophers.h"

unsigned long	current_time(void)
{
	static struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	prnt_sts(t_phlsphr *ph, char *status)
{
	unsigned long	t_stmp;

	t_stmp = current_time() - ph->t_strt;
	pthread_mutex_lock(ph->p_mtx);
	printf("%lu %d %s\n", t_stmp, ph->indx + 1, status);
	if (ph->alive)
		pthread_mutex_unlock(ph->p_mtx);
}

// void	wait_for(int intrvl)
// {
// 	unsigned long	stop_wait;

// 	stop_wait = current_time() + intrvl;
// 	while (1)
// 	{
// 		if (current_time() >= stop_wait)
// 			break;
// 		usleep(1);
// 	}
// }

// int		check_frks(t_phlsphr *ph)
// {
// 	if (*ph->lf_f == 1 && *ph->rf_f == 1)
// 		return (1);
// 	else
// 		return (0);
// }

int	get_frks(t_phlsphr *ph)
{
	pthread_mutex_t	get_f;

	if (pthread_mutex_init(&get_f, NULL)) //initializes fork mutexes
			err_message("Mutex was not initialised");
	if (*ph->lf_f == 1 && *ph->rf_f == 1)
	{
		pthread_mutex_lock(&get_f);
		pthread_mutex_lock(ph->lf_mtx);
		*ph->lf_f = 0;
		pthread_mutex_lock(ph->rf_mtx);
		*ph->rf_f = 0;
		pthread_mutex_unlock(&get_f);
		prnt_sts(ph, "has taken the right fork");
		prnt_sts(ph, "has taken the left fork");
		return (1);
	}
	else
	{
		// pthread_mutex_unlock(&get_f);
		return (0);
	}
}

void	release_frks(t_phlsphr *ph)
{
	// pthread_mutex_t	release_f;
	
	// if (pthread_mutex_init(&release_f, NULL)) //initializes fork mutexes
			// err_message("Mutex was not initialised");
	// pthread_mutex_lock(&release_f);
	*ph->lf_f = 1;
	pthread_mutex_unlock(ph->lf_mtx);
	*ph->rf_f = 1;
	pthread_mutex_unlock(ph->rf_mtx);
	// pthread_mutex_unlock(&release_f);
}

void	still_alive(t_phlsphr *ph)
{
	// ph->age = current_time() - ph->t_lst_ml;
	if (current_time() - ph->t_lst_ml >= *ph->t2d)
		ph->alive = 0;
}

// void	still_alive(t_phlsphr *ph)
// {
// 	ph->age = current_time() - ph->t_lst_ml;
// 	if (ph->age >= *ph->t2d)
// 		ph->alive = 0;
// }

void	ph_lives(t_phlsphr *ph)
{
	// write(1, "ppp\n", 4);
	ph->t_strt = current_time();
	ph->t_lst_ml = ph->t_strt;
	while (1)
	{
		if (ph->pr == *ph->h && get_frks(ph) == 1)
		{	
			ph->t_lst_ml = current_time();
			*ph->has_eatn++;
			ph->pr = *ph->l;
			prnt_sts(ph, "is eating");
			// wait_for(*ph->t2e);
			usleep(*ph->t2e);
			release_frks(ph);
			prnt_sts(ph, "is sleeping");
			// wait_for(*ph->t2s);
			usleep(*ph->t2s);
			prnt_sts(ph, "is thinking");
		}
		// else if (ph->pr == *ph->h || ph->pr == *ph->m)
			// wait_for(ph->pr);
			// usleep(ph->pr);
		still_alive(ph);
	}
}

void	launch_threads(t_prime *p)
{
	int			i;

	p->dly = 20;
	p->ph_ptid = (pthread_t *)ft_calloc(p->n_ph, sizeof(pthread_t)); //allocates memory to the array of ph_ptid
	
	// if (pthread_create(&p->mntr_ptid, NULL, (void *)monitor, p))
	// 	err_message("Thread was not created");
	i = 0;
	while (i < p->n_ph)
	{
		if (i == p->n_ph - 1)
			usleep(p->dly);
		if (pthread_create(&p->ph_ptid[i], NULL, (void *)ph_lives, &p->arr_ph[i]))
			err_message("Thread was not created");
		i += 2;
	}
	i = 1;
	usleep(p->dly);
	while (i < p->n_ph)
	{
		if (pthread_create(&p->ph_ptid[i], NULL, (void *)ph_lives, &p->arr_ph[i]))
			err_message("Thread was not created");
		i += 2;
	}
}
