#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int ft_strlen(char *c)
{
	int i = 0;
	printf("i = %d\n", i);
	while(c && c[i])
		i++;
	printf("i = %d\n", i);
	return(i);
}

int replace(char *s, char*r)
{
	int i = 0;
	int j = 0;

	i = 0;
	while(s[i])
	{
		j = 0;
		while(s[i + j] && s[i + j] == r[j])
		{
			j++;
		}
		if( j == ft_strlen(r))
		{
			write(0, "*", 1);
			i = i + j;
		}
		else
		{
			write(0, &s[i], 1);
			i++;
		}
	}
	return(0);
}


char *ft_read(void)
{

	char buf[BUFFER_SIZE];
	int read_size;
	char *c = NULL;
	int c_size = 0;

printf("passe0\n");
//	while(1)
//	{
		read_size = read(0, buf, BUFFER_SIZE);
		printf("passe1 read_size = %d\n", read_size);
		if(read_size < 0)
		{
			perror("Error");
			return(NULL);
		}
		if(read_size == 0)
			return(c);
		else
		{
			printf("passe2 ft_strlen(c) = %d\n", ft_strlen(c));
			c_size = ft_strlen(c) + read_size;
			printf("c_size = %d\n", c_size);
			c = realloc(c, c_size + 1);
			if(c < 0)
			{
				perror("Error");
				return(NULL);
			}
			printf("c_size = %d   read_size = %d\n", c_size, read_size);
			c[c_size] = '\0';
			while(read_size > 0)
			{
				c[c_size - 1] = buf[read_size - 1];
				read_size--;
				printf("c = %s\n", c);
			}
		}
//	}

}

int main(int argc, char **argv)
{
	char *c = NULL;
	if(argc != 2)
	{
		perror("Error");
		return(1);
	}

//	while(1)
	printf("passe00\n");
	c = ft_read();
	printf("c = %s\n", c);
//	replace(c, argv[1]);

//	printf("\n BUFFER_SIZE = %d fin\n", BUFFER_SIZE);


	return(0);
}


