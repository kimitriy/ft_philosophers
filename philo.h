#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

struct	s_one_of_philo;

typedef struct s_all_for_philo
{
	int						num; //number of philosophers
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						num_of_meals; //optional
	unsigned long			time_of_start;
	pthread_t				*thread;
	pthread_mutex_t			*fork;
	pthread_mutex_t			msg;
	pthread_mutex_t			time;
	struct s_one_of_philo	*fi;
}				t_all_for_philo;

typedef struct s_one_of_philo
{
	int				index; //philo's indx
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	unsigned long	last_eat; //time of the last meal
	int				already_ate; //number of times the philo has eaten
	int				well_fed_philo;
	t_all_for_philo	*info;
}				t_one_of_philo;

int				check_arguments(int argc, char **argv, t_all_for_philo *philo);
int				print_error(char *str);
unsigned long	current_time(void);
void			live_life(t_one_of_philo *philo);
void			*death_note(t_all_for_philo	*var);

#endif