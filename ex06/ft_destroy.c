#include <stdlib.h>

void	ft_destroy(char ***factory)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (factory[i])
	{
		j = 0;
		while (factory[i][j])
		{
			free(factory[i][j]);
			j++;
		}
		free(factory[i]);
		i++;
	}
	free(factory);
}

int		main(void)
{
	char	***triple_ptr;

	triple_ptr = malloc(sizeof(char **) * 2);
	triple_ptr[0] = malloc(sizeof(char *) * 2);
	triple_ptr[0][0] = malloc(sizeof(char) * 2);
	triple_ptr[0][0][1] = 'a';
	triple_ptr[0][0][2] = '\0';
	triple_ptr[0][1] = NULL;
	triple_ptr[1] = NULL;
	ft_destroy(triple_ptr);
	return (0);
}

// si par contre factory est l'ADRESSE d'un char**
// ce qui me parait peu probable... mais sait on jamais
void	ft_destroy_v2(char ***factory)
{
	int		i;
	int		j;

	i = 0;
	while ((*factory)[i])
	{
		free((*factory)[i]);
		i++;
	}
	free(*factory);
}

int		main(void)
{
	char	**double_ptr;

	double_ptr = malloc(sizeof(char *) * 2);
	double_ptr[0] = malloc(sizeof(char) * 2);
	double_ptr[0][0] = 'a';
	double_ptr[0][1] = '\0';
	double_ptr[1] = NULL;
	ft_destroy_v2(&double_ptr);
}
