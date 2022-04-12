#include "minishell.h"

char	*ft_find(char **env, char *str)
{
	int	i;
	int	j;

	i = 0;
    while (env[i])
	{
		j = 0;
		while (env[i][j])
		{
			while (env[i][j] == str[j])
				j++;
			if (str[j] == '\0')
				return (env[i]);
			else
				break ;
		}
		i++;
	}
	return (NULL);
}

/* ------------------------------------------------
    gestion des builtins suivant :
    - builtins suivantes :
        - echo et l’option -n
        - cd uniquement avec un chemin relatif ou absolu
        - pwd sans aucune option
        - export sans aucune option
        - unset sans aucune option
        - env sans aucune option ni argument
        - exit sans aucune option
    ------------------------------------------------ */

int ft_echo(t_parse *parse)
{
    int i;

    i = 0;
    if (parse->token->flag != NULL)
    {
        i++;
        printf("%s", parse->token->flag);
    }
    if (parse->token->files != NULL)
    {
        if (i > 0)
            printf(" ");
        printf("%s", parse->token->files);
        free(parse->token->files);
    }
    i = 0;
    if (strcmp(parse->token->flag, "-n") == 0)
    {
        free(parse->token->flag);
        return (1);
    }
    printf("\n");
    return (0);
}
int checkcmd(t_parse *parse)
{
    char *path;
    int i;
    int n;

    n = 0;
    i = 0;
    if (strcmp(parse->token->cmd, "echo") == 0)
        ft_echo(parse);
    if (strcmp(parse->token->cmd, "env") == 0)
    {
        while (parse->env[i])
            printf("%s\n", parse->env[i++]);
    }
    if (strcmp(parse->token->cmd, "unset") == 0)
        printf("unset has been entered\n");
    if (strcmp(parse->token->cmd, "pwd") == 0)
    {
        path = ft_substr(ft_find(parse->env, "PWD="), 4, 68);
        printf("%s\n", path);
    }
    return (0);
}