#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	/*
	for(초기식 i; 조건식i; 변화식i)	//바깥쪽 루프
	{
		for(초기식 j; 조건식j; 변화식j)	
		{
		실행할 코드
		}

		실행할 코드
	}
	
	*/

	int i, j;

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("j : %d ",j);
		}
		printf("i :%d\n", i);
		printf("\n");
	}

	/*
	j: 0 j:1 j:2 j:3 j:4 i:0\n
	j: 0 j:1 j:2 j:3 j:4 i:1\n
	j: 0 j:1 j:2 j:3 j:4 i:2\n
	j: 0 j:1 j:2 j:3 j:4 i:3\n
	j: 0 j:1 j:2 j:3 j:4 i:4\n
	*/

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("*");
		}	//별을 다섯 개 그릴때마다 제어문자를 실행함
		printf("\n");
	}


	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 7; j++)
		{
			printf("*");
		}	//별을 일곱 개 그릴때마다 제어문자를 실행함
		printf("\n");
	}

	for (i = 1; i <= 5; i++)
	{
		for (j = 1; j <= 5; j++)
		{	if(j <= i)	//i의 수만 큼 별 출력 
				printf("*");
		}
		printf("\n");
	}


	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (j == i)	//가로 방향과 세로 방향의 변수가
				//같을 때 별 출력, 다를 때 공백 출력
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}

	
	int num1;
		
		scanf("%d",&num1);
		for (i = 0; i < num1; i++)
		{
			for (j = 0; j < ((num1*2)-1); j++)
			{
				if ((num1-1-i) <= j && j <= num1 + i -1)	
					printf("*");
				else
					printf(" ");
			}
		printf("\n");
		}

		return 0;
}