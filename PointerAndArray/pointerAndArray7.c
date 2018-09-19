#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>	//malloc, free �Լ��� ����� �������
int main()
{
	/*
	���α׷� ���� �߿� ���ϴ� ũ�⸸ŭ �迭�� �����ϴ�
	����� �ִ�. �������̹迭(Variable_LengthArray,VLA)
	�������̹迭�� visual studio 2017������ �������� ����
	->������ ������ �߻���!, gcc, clang �� ������ ������
	ũ�⸦ �������� �����Ϸ��� �����͸� �����ϰ� �޸𸮸�
	�Ҵ��� �� �����͸� �迭ó�� ����ϸ� ��
	
	int size;

	scanf("%d", &size);

	int numArr[size];
	
	�����͸� �迭ó�� ����ϴ� ���-> �����Ϳ�
	malloc�Լ��� �޸𸮸� �Ҵ����ָ� �� 
	�ڷ��� *������ �̸� = malloc(sizeof(�ڷ���) * ũ��); 
	*/

	int *numPtr = malloc(sizeof(int) * 10);
	//int 10�� ũ�⸸ŭ�� �����޸� �Ҵ�
	//sizeof(int)�� ������ ������ �迭ó�� ����� �� ����
	//������[�ε���]; -> �迭ó�� �ε����� �����Ͽ�
	//���� �Ҵ��ϰų� ������ �� ����
	
	numPtr[0] = 10;
	numPtr[9] = 20;

	printf("%d\n", numPtr[0]);
	printf("%d\n", numPtr[9]);

	free(numPtr);
	//�޸� �Ҵ��� �� ����

	int size;

	scanf("%d", &size);

	int *numPtr2 = malloc(sizeof(int)*size);

	for (int i = 0; i < size; i++)
	{
		numPtr2[i] = i;
	}

	for (int i = 0; i < size; i++) 
	{
		printf("%d\n", numPtr2[i]);
	}

	free(numPtr2);
	
	/*
	�ڷ��� **�������̸� = 
	malloc(sizeof(�ڷ��� *) * ����ũ��);
	���� ���� �޸� �Ҵ� 

	�ݺ������� �ݺ��ϸ鼭 ������[i] = 
	malloc(sizeof(�ڷ���) * ����ũ��);
	���� ���� �޸� �Ҵ� 

	�ݺ������� �ݺ��ϸ鼭 free(������[i]); �� ����
	���� ���� �޸� ����
	*/

	int **m = malloc(sizeof(int *) * 3);
	//���� �����Ϳ� 2���� �迭�� ���� ������ �ش��ϴ�
	//�޸𸮸� �Ҵ���, �̶� ���� �������� ���� ���� 
	//�ʰ� ���� ������ �޸� �ּҰ� ��
	//sizeof(int *)�� �������� ũ�⸦ ���� �ڿ�
	//���� ũ�� 3�� ������ 

	for (int i = 0; i < 3; i++)
	{											
		m[i] = malloc(sizeof(int) * 4);
	//���� ũ�⸸ŭ �ݺ��ϸ鼭 2���� �迭�� ���� ������
	//�ش��ϴ� �޸� �ּҸ� �Ҵ����� 
	//m[0],m[1],m[2]�� pointer to int�̹Ƿ� int *�� ��
	}

	m[0][0] = 1;
	m[2][0] = 5;
	m[2][3] = 2;

	printf("%d\n", m[0][0]);
	printf("%d\n", m[2][0]);
	printf("%d\n", m[2][3]);

	for (int i = 0; i < 3; i++)
	{
		free(m[i]);
	}

	free(m);
	//���� ������ �ش��ϴ� �޸𸮸� ���� �����ع�����
	//���� ���� �޸𸮸� ������ �� �����Ƿ� ������ �� 

	int row, col;

	scanf("%d %d", &row, &col);

	int **m1 = malloc(sizeof(int*) * row);

	for (int i = 0; i < row; i++)
	{
		m1[i] = malloc(sizeof(int) * col);
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			m1[i][j] = i + j;
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d ", m1[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < row; i++)
	{
		free(m1[i]);
	}

	free(m1);
	
	
	int x;

	scanf("%d", &x);

	int **m2 = malloc(sizeof(int *) * x);

	for (int i = 0; i < x; i++)
	{
		m2[i] = malloc(sizeof(int) * x);
	}

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (i != j)
				m2[i][j] = 0;
			else
				m2[i][j] = 1;
		}
	}

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++)
		{
			printf("%d ", m2[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < x; i++)
	{
		free(m2[i]);
	}

	free(m2);




	return 0;

}