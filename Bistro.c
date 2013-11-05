#include <stdlib.h>
#include <stdio.h>

void	my_putchar(char c)
{
	write(1, &c, 1);
}

void	my_putstr(char *str)
{
	int i;

	i = 0;

	while (str[i] != '\0')
	{
		my_putchar(str[i]);
		i = i + 1;
	}
}

int		my_strlen(char *str)
{
	int i;

	i = 0;

	while(str[i] != '\0')
	{
		i = i + 1;
	}

	return (i);
}


int		mk_ans(int taille)
{
	char *ans;
	int i = 0;

	ans = malloc((sizeof(char)*(taille + 1)));
	while( i < (taille + 1))
	{
		ans[i] = '0';
		i++;
	}
	ans[i] = '\0';
	return ans;
}

char	add(char *n1, char *n2, char *ans)
{
	int i;
	int p1;
	int p2;
	int count;
	int retenue;

	i = 0;
	retenue = 0;
	p1 = (my_strlen(n1) - 1);
	p2 = (my_strlen(n2) - 1);
	count = p1 + 1;

	while (count > 0)
	{
		ans[p1] = '0' + ((n1[p1] - '0') + (n2[p2] - '0')) + retenue;
		if (ans[p1] > '9')
		{
			ans[p1] = ans[p1] - 10;
			retenue = 1;	
		}
		else
			retenue = 0;
		p1 = p1 - 1;
		p2 = p2 - 1;
		count = count - 1;
	}
}

int		main(int argc, char **argv[])
{
	int t1;
	int t2;
	char *ans;

	if (argc < 2)
		return (0);
	else
	{
		t1 = my_strlen(argv[1]);
		t2 = my_strlen(argv[2]);
		if (t1 > t2)
			ans = mk_ans(t1);
		else
			ans = mk_ans(t2);

		add(argv[1], argv[2], ans);
		my_putstr(ans);

	}
	return 0;
}