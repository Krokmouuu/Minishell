#include "../minishell.h"

char	*ft_strjoin(char const *s1, char const *s2, int n)
{
	int		i;
	char	*str;

	i = 0;
	i = ft_strlen(s1);
	n = ft_strlen(s2);
	str = malloc((i + n) + 2 * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i++] = '/';
	n = 0;
	while (s2[n])
	{
		str[i + n] = s2[n];
		n++;
	}
	str[i + n] = '\0';
	return (str);
}