#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>	//srand, rand�Լ��� ����� �������
#include<time.h>	//time�Լ��� ����� �������
#include<stdbool.h>
int main()
{	/*
	�ʱ��
	do
	{
	�ݺ��� �ڵ�	--> ���� ��ü �� ��ȭ��
	��ȭ��
	}while(���ǽ�); -->���� ���� 
	���� ����: �ڵ�� ��ȭ�� ���� -> ���ǽ��� ���̸� �ٽ� 
	���� ��ü(�ڵ�� ��ȭ��) ����, �����̸� �ݺ�����
	�������� ���� �ڵ� ����
	*/

	int i = 0; // �ʱ��

	do
	{
		printf("Hellom world! %d\n", i);	//�ݺ��� �ڵ�
		i++;	//��ȭ��
	} while (i < 7);	//���ǽ�
	//���ǽĿ� ������� ������ �� ���� �����
	//��ȭ���� ������ ���� ������ �� �� �����Ƿ� ������ ��

	i = 1;

	do 
	{
		printf("Hello, world! %d\n", i);
		i++;
	} while (i <= 13);	//i�� 14�� �� �� �ݺ����� ����

	i = 13;
	
	do
	{
		printf("Hello, world! %d\n", i);
		i--;
	} while (i > 0);

	int count;

	scanf("%d", &count);

	i = 0;
	do
	{
		printf("Hello, world! %d\n", i);
		i++;
	} while (i < count);	//count��ŭ �ݺ�Ƚ�� ����


	scanf("%d", &count);

	do
	{
		printf("Hello, world! %d\n", count);
		count--;	//�ݺ����� ����� ������ count ����
	} while (count>0);	//count��ŭ �ݺ�Ƚ�� ����

	srand(time(NULL));	
	//srand : ������ �߻���ų �õ�(seed)�� ������, ���� ����
	//�ð� ���� �����, rand: ������ �߻���Ŵ
	//time: ���� ���·� �� ���� �ð� ���� ��ȯ�� 

	i = 0;
	do
	{
		i = rand() % 10;	//rand�Լ��� �̿��Ͽ� ��������
		//������ �����ϴµ� �̶� 10 �̸��� ���ڷ� ������
		printf("%d\n", i);
	} while (i != 3);	//i�� 3�� ���� �� �ݺ����� ����

	//do
	//{
	//	printf("Hello, world!\n");
	//} while (1); //while�� 1 �Ǵ� true�� �����ϸ� ���ѷ���

	do
	{
		printf("Hello, world!\n");
	} while (false); //0�Ǵ� false�� �����ϸ� �ڵ尡 �� ����
	//�����, �ݺ����� �ݺ������� ���� �߿��� 

	/*
		sum += i;
		i++;
	
	*/

	return 0;
}