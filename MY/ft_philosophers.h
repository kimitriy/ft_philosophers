#ifndef FT_PHILOSOPHERS_H
# define FT_PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct	s_phlsphr
{
	int				indx; //philosopher's index
	pthread_mutex_t	*lfrk;
	pthread_mutex_t	*rfrk;
	unsigned long	l_ml_time; //time since start of the last meal
	int				n_mls_h_eatn; //number of meals philosopher has eaten to the moment
}					t_phlsphr;

typedef struct	s_prime
{
	int				n_ph; //number_of_philosophers
	int				t2d; //time_to_die
	int				t2e; //time_to_eat
	int				t2s; //time_to_sleep
	int				n_mls_m_eat; //number_of_times_each_philosopher_must_eat
	t_phlsphr		*arr_ph; //array of philosophers
}					t_prime;

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

/*main.c*/
int						main(int argc, char **argv);

#endif