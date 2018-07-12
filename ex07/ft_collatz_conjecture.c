#include <stdio.h>

unsigned int	ft_collatz_conjecture(unsigned int base)
{
	if (base == 1)
		return (0);
	if (base % 2 == 0)
		return (1 + ft_collatz_conjecture(base / 2));
	else
		return (1 + ft_collatz_conjecture(3 * base + 1));
}

int				main(void)
{
	int		base = 15;
	int		tdv;

	tdv = ft_collatz_conjecture(15);
	printf("temps de vol pour %d = %d\n", base, tdv);
	return (0);
}
