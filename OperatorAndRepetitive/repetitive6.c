#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	/*
	for(�ʱ�� i; ���ǽ�i; ��ȭ��i)	//�ٱ��� ����
	{
		for(�ʱ�� j; ���ǽ�j; ��ȭ��j)	
		{
		������ �ڵ�
		}

		������ �ڵ�
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
		}	//���� �ټ� �� �׸������� ����ڸ� ������
		printf("\n");
	}


	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 7; j++)
		{
			printf("*");
		}	//���� �ϰ� �� �׸������� ����ڸ� ������
		printf("\n");
	}

	for (i = 1; i <= 5; i++)
	{
		for (j = 1; j <= 5; j++)
		{	if(j <= i)	//i�� ���� ŭ �� ��� 
				printf("*");
		}
		printf("\n");
	}


	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (j == i)	//���� ����� ���� ������ ������
				//���� �� �� ���, �ٸ� �� ���� ���
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