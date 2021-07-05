#ifndef FT_PHILOSOPHERS_H
# define FT_PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

/*
t_lst_ml - time since start of the last meal
*/
typedef struct s_phlsphr
{
	int					indx;
	int					*t2d;
	int					*t2e;
	int					*t2s;
	pthread_mutex_t		*lfrk;
	pthread_mutex_t		*rfrk;
	int					has_eatn;
	unsigned long		t_strt;
	unsigned long		t_lst_ml;
}						t_phlsphr;

/*
n_ph - number_of_philosophers
t2d - time_to_die
t2e - time_to_eat
t2s - time_to_sleep
n_mls_m_eat - number_of_times_each_philosopher_must_eat
arr_frk - array of forks
ph_ptid - array of philosopher pthreads
arr_ph - array of philosophers
*/
typedef struct s_prime
{
	int					n_ph;
	int					t2d;
	int					t2e;
	int					t2s;
	int					n_mls_m_eat;
	pthread_mutex_t		*arr_frk;
	pthread_t			*ph_ptid;
	t_phlsphr			*arr_ph;
}						t_prime;

/*utils1.c*/
void					ft_bzero(void *s, size_t n);
int						err_message(char *error);
void					err_memory_allocation_error(void);
void					*ft_calloc(size_t count, size_t size);
int						ft_strlen(const char *s);

/*utils2.c*/
int						ft_isdigit(int c);
unsigned long long int	ovrloading_protection(unsigned long long int n, \
						int sign);
int						ft_atoi(const char *str);

/*prsr.c*/
int						is_a_number(char *str);
int						prs_argv(int argc, char **argv, t_prime *p);
int						prsr(int argc, char **argv, t_prime *p);

/*pthreads1.c*/
unsigned long			current_time(void);
void					prnt_sts(t_phlsphr *ph, char *status);
void					get_frks(t_phlsphr *ph);
void					release_frks(t_phlsphr *ph);
void					*ph_lives(void *ph);

/*pthreads2.c*/
void					launch_threads(t_prime *p);

/*monitor.c*/
void					kill_ph(t_prime *p);
int						is_dead(t_prime *p);
int						is_fed(t_prime *p);
void					monitor(t_prime *p);

/*main.c*/
void					mtx_init(t_prime *p);
void					ph_init(t_prime *p, int ix);
void					arr_ph_init(t_prime *p);
int						main(int argc, char **argv);

#endif