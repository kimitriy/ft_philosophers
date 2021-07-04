#include "ft_philosophers.h"

int	is_a_number(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (err_message("Wrong argument!")); //returns 0 if char is not a digit
		i++;
	}
	return (1); //thus returns 1 if the str is a number and 0 if it is not
}

int	prs_argv(int argc, char **argv, t_prime *p) 
{
	if (is_a_number(argv[1]))
		p->n_ph = ft_atoi(argv[1]);
	else
		return (0);
	if (is_a_number(argv[2]))
		p->t2d = ft_atoi(argv[2]);
	else
		return (0);
	if (is_a_number(argv[3]))
		p->t2e = ft_atoi(argv[3]);
	else
		return (0);
	if (is_a_number(argv[4]))
		p->t2s = ft_atoi(argv[4]);
	else
		return (0);
	if (argc == 5)
		p->n_mls_m_eat = 0;
	else if (argc == 6 && is_a_number(argv[5]))
		p->n_mls_m_eat = ft_atoi(argv[5]);
	else
		return (0);
	return (1);
}

int	prsr(int argc, char **argv, t_prime *p)
{
	if (argc != 5 && argc != 6)
		return (err_message("Wrong number of arguments!"));
	if (!prs_argv(argc, argv, p))
		return (0);
	if (p->n_ph > 200 || p->n_ph < 1)
		return (err_message("Wrong number of philosophers!"));
	if (p->t2d < 60 || p->t2e < 60 || p->t2s < 60)
		return (err_message("Wrong time_to_die / time_to_eat / time_to_sleep!"));
	return (1);
}