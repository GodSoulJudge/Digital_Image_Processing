#include<stdio.h>
#include"secret.h"

void secret_f(char*p, int n,int k) {
	int m = n % 26;
	for (int i = 0; i < k; i++)
	{
		if ((p[i] <= 'z'&&p[i] >= 'a') || (p[i] >= 'A'&&p[i] <= 'Z'))
			if ((p[i] + m) > 'z' || ((p[i] + m) > 'Z' && (p[i]) < 'a'))
				p[i] += (m - 26);
			else
				p[i] += m;
	}

}