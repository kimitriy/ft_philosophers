#ifndef FT_PHILOSOPHERS_H
# define FT_PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct	s_phlsphr
{
	int					indx; //philosopher's index
	int					alive; //if alive == 1, dead == 0
	int					*pr; //priority 1 (high), 2 (middle), 3 (low)
	int					*t2d; //points to t_prime->t2d
	int					*t2e; //points to t_prime->t2e
	int					*t2s; //points to t_prime->t2s
	int					*lf_f; //left fork flag, 0 - fork is locked, 1 - fork is available
	int					*rf_f; //right fork flag, 0 - fork is locked, 1 - fork is available
	pthread_mutex_t		*lf_mtx; //pointer to the left fork
	pthread_mutex_t		*rf_mtx; //pointer to the right fork
	pthread_mutex_t		*p_mtx; //pointer to t_prime->print_mtx
	unsigned long		t_strt; //start time
	unsigned long		t_lst_ml; //time since start of the last meal
	int					have_eatn; //number of meals philosopher has eaten to the moment
}						t_phlsphr;

typedef	struct	s_mntr
{
	int					h;
	int					m;
	int					l;
	int					*pr; //arr where the monitor assigns priority level to each phi
	int					*n_mls_ate; //arr where the monitor saves how many time each phi ate
}						t_mntr;

typedef struct	s_prime
{
	int					n_ph; //number_of_philosophers
	int					t2d; //time_to_die
	int					t2e; //time_to_eat
	int					t2s; //time_to_sleep
	int					n_mls_m_eat; //number_of_times_each_philosopher_must_eat
	int					*arr_ff; //array of fork flags
	pthread_mutex_t		*arr_mtx; //array of mutexes (forks)
	pthread_mutex_t		prnt_mtx; //mutex that is used to lock pthread while printing its status
	pthread_t			*ph_thread; //array of philosopher threads
	t_phlsphr			*arr_ph; //array of philosophers
	t_mntr				mntr; //
}						t_prime;

/*utils.c*/
void					ft_bzero(void *s, size_t n);
int						err_message(char *error);
void					err_memory_allocation_error(void);
void					*ft_calloc(size_t count, size_t size);
int						ft_strlen(const char *s);
int						ft_isdigit(int c);
unsigned long long int	ovrloading_protection(unsigned long long int n, int sign);
int						ft_atoi(const char *str);

/*prsr.c*/
int						is_a_number(char *str);
int						prs_argv(int argc, char **argv, t_prime *p);
int						prsr(int argc, char **argv, t_prime *p);

/*pthreads.c*/
void					prnt_sts(t_phlsphr *ph, char *status);
void					wait_for(int intrvl);
int						check_frks(t_phlsphr *ph);
void					get_frks(t_phlsphr *ph);
void					ph_lives(t_phlsphr *ph);
void					launch_threads(t_prime *p);

/*monitor.c*/

void					monitor(t_prime *p);

/*main.c*/
void					mtx_init(t_prime *p);
void					ph_init(t_prime *p, int ix);
void					arr_ph_init(t_prime *p);
int						main(int argc, char **argv);

#endif