#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	/*
	if, else�� ���ǽ��� ��, ������ �� �� ������ ó���� ��
	����, else if�� ���� ������ ó���� �� ������ �Ź� 
	���ǽ��� �����ؾ� �ϴ� ���ŷο��� ����
	switch���� ������ ���Ƶ� �ս��� ó���� ���� ����
	switch(num1)<-- ���� �Ǵ��� ����
	{
	case 1: //num1�� 1�� �� ���� 
		printf("1�Դϴ�.\n");
		break;
	case 2: //num1�� 2�� �� ����
		printf("2�Դϴ�.\n");
		break;
	defalut: //�ƹ� case���� �ش����� ���� �� ������
		printf("3�Դϴ�.\n");
		break;
		//defalut�� ������ ������
	}

	*/


	int num1;

	scanf("%d", &num1);
	//���ǽ��� �ٲ��� �ʰ� ���� �ٲ� ���� switch���� ������
	switch (num1) //��ȣ �ȿ� ���� �Ǵ��� ����
	{
	case 1:	//num1�� 1�� �� 
		printf("1�Դϴ�.\n");
		break;
	case 2:	//num1�� 2�� �� 
		printf("2�Դϴ�.\n");
		break;
	default:	//�ƹ� case���� �ش���� ���� �� 
		printf("default\n");
		break;
	}

	//���� ���ǽ��� ��� �ٲ� ���� else if�� ������ 
	if (num1 == 1)
		printf("1�Դϴ�.\n");
	else if (num1 == 2)
		printf("2�Դϴ�.\n");
	else
		printf("default\n");

	

	int num2;

	scanf("%d", &num2);
	//���ǽ��� �ٲ��� �ʰ� ���� �ٲ� ���� switch���� ������
	switch (num2) //��ȣ �ȿ� ���� �Ǵ��� ����
	{
	case 1:	//num2�� 1�� �� 
		printf("1�Դϴ�.\n");
	case 2:	//num2�� 2�� �� 
		printf("2�Դϴ�.\n");
	default:	//�ƹ� case���� �ش���� ���� �� 
		printf("default\n");
	}
	//case�� �ߴ����� ������ �� ������ �ִ� case�� ��� ����
	//��, �̷� ��Ȳ�� fall through��� �θ��� "���� ���̷�
	//��������"���� ������ ����
	//default �������� ������ case�� �����Ƿ� 
	//break�� �־�ǰ� �� �־ �� 

	int num3, num4;

	scanf("%d", &num3);
	//���ǽ��� �ٲ��� �ʰ� ���� �ٲ� ���� switch���� ������
	switch (num3) //��ȣ �ȿ� ���� �Ǵ��� ����
	{
	case 1:	//num3�� 1�� �� 
	case 2:	//num3�� 2�� ��
		printf("1 �Ǵ� 2�Դϴ�.\n");
		break;
	case 3:	//num3�� 3�� �� 
	case 4:	//num3�� 4�� �� 
		printf("3 �Ǵ� 4�Դϴ�.\n");
		break;
	default:	//�ƹ� case���� �ش���� ���� �� 
		printf("defalut\n");
		break;
	}
	//case���� break ���� �����ϸ� �������� ������ ���� �ڵ�
	//�� �����ų ���� ���� 

	scanf("%d", &num4);
	if (num4 == 1 || num4 == 2)
		printf("1 �Ǵ� 2�Դϴ�.\n");
	else if (num4 == 3 || num4 == 4)
		printf("3 �Ǵ� 4�Դϴ�.\n");
	else
		printf("default\n");
	//if, else if�� ������ ���ǽ��� �����ؾ� �Ǽ� ó����
	//���ڰ� �������� �ſ� ���ŷο���-> �̷� ����
	//case���� break�� �����ϴ� ����� ������


	//case���� ������ �����Ϸ��� �߰�ȣ�� ������ߵ�
	//case���� ������ ������ case�ȿ����� ����� �����ϰ� 
	//case �ۿ����� switch�� �ۿ����� ����� �� ��

	int num5;

	scanf("%d", &num5);
	//���ǽ��� �ٲ��� �ʰ� ���� �ٲ� ���� switch���� ������
	switch (num5) //��ȣ �ȿ� ���� �Ǵ��� ����
	{
	case 1: {	//num5�� 1�� ��
		int num6 = 3;
		printf("1�Դϴ�.\n");
		break;
	}
	case 2:	//num5�� 2�� �� 
		printf("2�Դϴ�.\n");
		break;
	default:	//�ƹ� case���� �ش���� ���� �� 
		printf("default\n");
	}

	//switch�� �Ǻ��� �� �ִ� �ڷ����� ���� �ڷ����� ����
	//���� �ڷ����� char�� ������, �Ǽ��� ���ڿ� ���� �� ��

	char c1,c2;
	scanf("%c", &c2);
	scanf("%c", &c1);

	switch (c1)
	{
	case 'a':
		printf("a�Դϴ�.\n");
		break;
	case 'b':
		printf("b�Դϴ�.\n");
		break;
	default:
		printf("default\n");
		break;
	}

	return 0;
}