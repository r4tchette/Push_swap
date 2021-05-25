#include "push_swap.h"

int		ft_strequ(char *s1, char *s2, int len)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	if (ft_strlen(s1) == 0 || ft_strlen(s2) == 0)
		return (0);
	while (i < len)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
