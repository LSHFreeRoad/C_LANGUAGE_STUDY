#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	/*
	break�� for, while, do while, switch������ ���� �帧��
	����� ���� �����, continue�� �����帧��
	������ ���¿��� �ڵ��� ���ุ �ǳʶ� �ݸ鿡
	break�� �����帧�� �ߴ��ϰ� ��������
	
	*/
	int num1 = 0;

	while (1)
	{
		num1++;
		printf("%d\t", num1);
		if (num1 == 7)	//num1�� 7�̸� �ݺ����� ����
			break;
	}

	num1 = 0;
	printf("\n");

	for(;;)
	{
		num1++;
		printf("%d\t", num1);
		if (num1 == 6)	//num1�� 6�̸� �ݺ����� ����
			break;
	}
	printf("\n");
	int i = 0;
	for (i = 1; i <= 13; i++)
	{
		if (i % 2 != 0)	//¦���� ��µǵ��� �ϱ�
			continue;	//Ȧ���� continue �Ʒ��� �ڵ�� ����
		//���� �ʰ� �ǳʶ� �Ŀ� �ݺ����� �ٽ� ������
		printf("%d\n", i);	
	}
	i = 1;
	while (i <= 16)
	{
		i++;
		if (i % 2 != 0)
			continue;
		printf("%d\n", i);
	}

	int count;

	scanf("%d", &count);

	i = 1;
	while (1)
	{
		printf("%d\n", i);
		if (i == count)
			break;

		i++;
	}

	scanf("%d", &count);

	for (i = 1; i <= count; i++)
	{

		if (i % 2 != 0)	//i�� Ȧ���϶��� �ǳʶٰ� ¦���϶���
			//����ϵ��� ������
			continue;

		printf("%d\n", i);
	}



	return 0;
}