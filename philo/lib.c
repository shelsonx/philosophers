#include "philo.h"

static int	ft_isspace(int c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9'));
}

int	ft_atoi(const char *src)
{
	int	sign;
	int	res;

	while (ft_isspace(*src))
		src++;
	sign = 1;
	res = 0;
	if (*src == '-')
		sign *= -1;
	if (*src == '-' || *src == '+')
		src++;
	while (ft_isdigit(*src))
	{
		res = (res * 10) + (*src - '0');
		src++;
	}
	return (res * sign);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
