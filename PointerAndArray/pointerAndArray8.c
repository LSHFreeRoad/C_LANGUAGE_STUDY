#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int m, n, count = 0, i, j;
	scanf("%d %d", &m, &n);
	char **matrix = malloc(sizeof(char *) * m);

	for (i = 0; i < m; i++)
	{	matrix[i] = malloc(sizeof(char) * (n + 1));
	}


	for(i = 0; i < m; i++)
	{
		scanf("%s", matrix[i]);
	}

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < (n + 1); j++)
		{
			if (matrix[i][j] == '*')
			{	
				printf("%c", matrix[i][j]);
				continue;	
			}
			else if (matrix[i][j] == '.')
			{			
				if(j >= 1 && matrix[i][j - 1] == '*')
					count++;
				if(j <= n-2 && matrix[i][j + 1] == '*')
					count++;
				if (i >= 1 && j >= 1 &&
					matrix[i - 1][j - 1] == '*')
					count++;
				if (i >= 1 && matrix[i - 1][j] == '*')
					count++;
				if (i >= 1 && j <= n-2 &&
					matrix[i - 1][j + 1] == '*')
					count++;
				if (i <= m-2 && j >= 1 &&
					matrix[i + 1][j - 1] == '*')
					count++;
				if (i <= m-2 && matrix[i + 1][j] == '*')
					count++;
				if (i <= m-2 && j <= n-2 &&
					matrix[i + 1][j + 1] == '*')
					count++;

				matrix[i][j] = count;
				
			printf("%d", matrix[i][j]);
			count = 0;
			}
			
		}
		printf("\n");
	}

	return 0;
}
