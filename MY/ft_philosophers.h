#ifndef FT_PHILOSOPHERS_H
# define FT_PHILOSOPHERS_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>



/*utils.c*/
void	ft_bzero(void *s, size_t n);
void	err_message(char *error);
void	err_memory_allocation_error(void);
void	*ft_calloc(size_t count, size_t size);
int	ft_strlen(const char *s);
int	ft_isdigit(int c);
unsigned long long int	ovrloading_protection(unsigned long long int n, int sign);
int	ft_atoi(const char *str);

/*main.c*/

#endif