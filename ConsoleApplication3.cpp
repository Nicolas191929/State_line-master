#include "pch.h"
#include <iostream>
#include <stdio.h>

#define START 1
#define NO_COM 2
#define COM 3
#define POSSIBLE_COM 4
#define LAPKI 5
#define POSSIBLE_END_COM 6
int main()
{
	char str[50] = "/q/we/*qwewew*/qr'/*qw*/'";
	char buf[50];
	char str2[50] = "";
	printf("Vvedit` ryadki\n");
	fgets(buf, 50, stdin);
	char q;
	int i = 0, k = 0;
	int s = 1;
	while ((q = str[i]) != '\0')
	{
		switch (s)
		{
		case START:
			if (q == '/')
				s = POSSIBLE_COM;
			else if (q == '\"')
				s = LAPKI;
			else
				s = NO_COM;
			break;
		case NO_COM:
			if (q == '/')
				s = POSSIBLE_COM;
			else
			{
				if (q == '\"')
					s = LAPKI;
				str2[k] = q;
				k++;
			}
			break;
		case COM:
			if (q == '*')
				s = POSSIBLE_END_COM;
			break;
		case POSSIBLE_COM:
			if (q == '*')
				s = COM;
			else
			{
				if (q == '\"')
					s = LAPKI;
				else
					s = NO_COM;
				str2[k] = '/';
				str2[k + 1] = q;
				k += 2;
			}
			break;
		case LAPKI:
			if (q == '\"')
				s = NO_COM;
			str2[k] = q;
			k++;
			break;
		case POSSIBLE_END_COM:
			if (q == '/')
			{
				s = NO_COM;
				str2[k] = ' ';
				k++;
			}
			break;
		}
		i++;
	}
	printf("%s", str2);
	return 0;
}

