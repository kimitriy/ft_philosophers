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
	int					*t2d; //points to t_prime->t2d
	int					*t2e; //points to t_prime->t2e
	int					*t2s; //points to t_prime->t2s
	pthread_mutex_t		*lfrk; //points to left fork
	pthread_mutex_t		*rfrk; //points to right fork
	pthread_mutex_t		*p_mtx; //pointer to t_prime->print_mtx
	int					has_eatn; //pointer to arr_has_eatn[i]
	unsigned long		t_strt; //start time : ph_lives()
	unsigned long		t_lst_ml; //time since start of the last meal : ph_lives()
}						t_phlsphr;

typedef struct	s_prime
{
	int					n_ph; //number_of_philosophers : prsr
	int					t2d; //time_to_die : prsr
	int					t2e; //time_to_eat : prsr
	int					t2s; //time_to_sleep : prsr
	int					n_mls_m_eat; //number_of_times_each_philosopher_must_eat : prsr
	pthread_mutex_t		*arr_frk; //array of forks
	pthread_mutex_t		prnt_mtx; //mutex that is used to lock pthread while printing its status : mtx_init
	pthread_t			*ph_ptid; //array of philosopher pthreads : launch_threads
	t_phlsphr			*arr_ph; //array of philosophers : arr_ph_init
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
void					ft_putnbr(unsigned int n);
// int						arr_min(int *arr);

/*prsr.c*/
int						is_a_number(char *str);
int						prs_argv(int argc, char **argv, t_prime *p);
int						prsr(int argc, char **argv, t_prime *p);

/*pthreads.c*/
unsigned long			current_time(void);
void					prnt_sts(t_phlsphr *ph, char *status);
void					wait_for(int intrvl);
// int						check_frks(t_phlsphr *ph);
void					get_frks(t_phlsphr *ph);
void					*ph_lives(void *ph);
void					launch_threads(t_prime *p);

/*monitor.c*/
void					change_priority(t_prime *p);
void					priority_node(t_prime *p);
void					kill_ph(t_prime *p);
int						is_dead(t_prime *p);
void					monitor(t_prime *p);

/*main.c*/
void					mtx_init(t_prime *p);
void					ph_init(t_prime *p, int ix);
void					arr_ph_init(t_prime *p);
int						main(int argc, char **argv);

#endif