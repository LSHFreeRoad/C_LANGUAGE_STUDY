#include<stdio.h>
int main()
{
	/*
	if(���ǽ�)
	{
	
	}else if(���ǽ�)
	{

	}else
	{

	}
	
	
	*/

	int num1 = 20;

	if (num1 == 10)
		printf("10�Դϴ�.\n");
	else if (num1 == 20)	//if�� ������ �� 
		//else if�� ���̶�� �ؿ� �ڵ� ����
		//else if�� ���� �����ݷ��� ���̸� �ȵ� 
		printf("20�Դϴ�.\n");

	int num2 = 30;

	if (num2 == 10)
		printf("10�Դϴ�.\n");
	else if (num2 == 20)
		printf("20�Դϴ�.\n");
	else
		printf("10�� 20�� �ƴմϴ�.\n");

	//if, else if�� ��� ������ �� else �ؿ� �ڵ尡 �����
	//else if�� ���� �� ��밡����
	//else if �տ� else�� ���� ������ ������ �߹Ƿ� ����!

	return 0;



}