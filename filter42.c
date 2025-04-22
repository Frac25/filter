#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdarg.h>

int filter(char *a)
{
	char buf[2];
	int nb_read;
	char *s;
	int i;

	buf[0] = '\0';
	buf[1] = '\0';
	s = NULL;
	nb_read = 1;


	while (nb_read > 0)
	{
		i = 0;
		buf[0] = '\0';
		while(buf[0] != '\n')
		{
			nb_read = read(0, buf, 1);
			if(nb_read <= 0)
				break;
			else
			{
				s = realloc(s, sizeof(char) * (i + 2));
				s[i] = buf[0];
			}
			i++;
		}

		if(nb_read <= 0)
			break;

		s[i] = '\0';

		printf("filtrer : s = %s         et a = %s\n", s, a);
	}
	return(0);
}

int main(char argc, char **argv)
{
	if(argc != 2)
	{
		printf("argc KO");
		return(1);
	}

	filter(argv[1]);

	return(0);
}