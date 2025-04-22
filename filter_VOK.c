#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdarg.h>

int ft_strlen (char *c)
{
	int i = 0;

	if(c == NULL)
		return(0);
	while (c[i])
		i++;
	return(i);
}

char *buffer()
{
	char buf[1];
	int nb_read;
	char *s;
	int i = 0;

	s = NULL;
	
	while (1)
	{
		nb_read = read(0, buf, 1);
		if(nb_read < 0)
		{
			free(s);
			return(NULL);
		}
		if(nb_read == 0)
			return(s);
		s = realloc(s, sizeof(char) * (i + 2));
		if(s == NULL)
		{
			free(s);
			return(NULL);
		}
		s[i] = buf[0];
		s[i+1] = '\0';
		i++;
	}
	return(NULL);
}

int main(int argc, char **argv)
{
	char *s;
	int i = 0;
	int j;
	int k;

	if(argc != 2 || argv[1][0] == '\0')
	{
		printf("argc KO");
		return(1);
	}

	s = buffer();
	if(s == NULL)
	{
		return(-1);
	}
//	printf("filter : s = %s\na = %s\n", s, argv[1]);

	while (s[i])
	{
		j = 0;
		while(s[i] && s[i] == argv[1][j])
		{
			i++;
			j++;
		}
		if(j == ft_strlen(argv[1]))
		{
			k = 0;
			while (k < j)
			{
				write(1, "*",1);
				k++;
			}
		}
		else
		{
			i = i - j;
			write(1, &s[i],1);
			i++;
		}
	}

	free(s);
	return(0);
}