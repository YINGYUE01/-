#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int i, j, k;
	for (i = 1; i <= 9; i++)
	{
		for (j = i,k=1; k<=i;k++)
		{
			printf("%d*%d=%-2d ", k, j, k * j);
		}
		printf("\n");

	}
}