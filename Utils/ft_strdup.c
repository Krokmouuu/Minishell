#include "../minishell.h"

char	*ft_strdup(const char *c)
{
	int		i;
	char	*str;

	i = 0;
	while (c[i])
		i++;
	str = malloc(i * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (c[i])
	{
		str[i] = c[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}