#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	/*
	for�ݺ���
	for(�ʱ�� ; ���ǽ� ; ��ȭ��)	//���� ����
	{
	�ݺ��� �ڵ� 
	}	//���� ��ü
	
	�ʱ�� ���� �����ؼ� ���ǽ��� �Ǻ� -> ���̸� ������ ����
	�ϰ� ��ȭ���� ������ -> �ٽ� ���ǽ��� �Ǻ��Ͽ� ���̸�
	�ڵ带 �����ϰ� �����̸� �ݺ����� ���� �� ���� �ڵ带
	������, ���ǽ� -> ���� ��ü -> ��ȭ�� -> ���ǽ����� 
	��ȯ�ϴ� �κ��� ������� �θ� 
	*/

	int i;
	for (i = 1; i <= 13; i++)
	{
		printf("Hello, world!\t");
		if (i % 5 == 0)
			printf("\n");
	}
	//��ȭ���� ��ȭ���� �� �� ������ �� ���� �� ���� ������	
	//for �ݺ����� �ݺ� Ƚ���� ������ ���� �� ������

	for (i = 0; i < 10; i++)
	{
		printf("Hello, world!\n");
	}
	printf("%d\n", i);	//i�� 10�� �� �� ���������Ƿ�

	for (i = 1; i <= 13 ; i++)
	{
		printf("Hello, world! %d\n",i);
	}//13�϶� �ݺ����� ����

	
	for ( i = 16; i > 0 ; i--)
	{
		printf("Hello, world! %d\n",i);
	} //i�� 0�϶� �ݺ����� ����

	//for (i = 0; i < 100; i++);
	//{
	//	printf("Hello, world! %d\n", i);
	//}
	//for �ݺ��� �ڿ� �����ݷ��� ���̸� �� ��
	//�����ݷ��� ���̰� �Ǹ� ������ �ڵ尡 ��
	//for (i = 0; i < 100; i++);
	//	printf("Hello, world! %d\n", i);

	for (i = 0; i < 13; i++)
		printf("Hello, world! %d\n", i);

	//for�ݺ������� ������ �ڵ尡 �� ���̸� �߰�ȣ ������
	//������, ������ �ڵ尡 2���̻��̸� �� �߰�ȣ�� ��ߵ�
	//���� ������ ù��° �ڵ常 �ݺ����� �����

	int count;

	scanf("%d", &count);

	for ( i = 0; i < count; i++)
	{
		printf("Hello, world! %d\n", i);
	}
	

	for (i = count; i > 0; i--)
	{
		printf("Hello, world! %d\n", i);
	}

	for (; count > 0; count--)
	{
		printf("Hello, world! %d\n", count);
	} //�ʱ갪 ���� : for�ݺ����� ����� ������ �ʱ갪��
	//�غ�Ǿ� ������ �ʱ갪 �κ��� ������ �� ����
	int j;

	for (i = 0,j = 0; i < 7; i++, j+=2)
	{
		printf("i : %d, j : %d\n", i, j);
	}// for�ݺ������� ������ 2�� �̻� ����ϴ� ���� ������
	// ��ȭ�Ŀ��� ���� �����ڸ� ����� �� ���� 
	//�� �����ڸ� ���ǽĿ� ����ؼ� i, j�� ���ÿ�
	//�˻��� ���� ���� 

	for (;;)
	{
		printf("Hello, world!\n");
	}//���ѷ���, CTRL+C�� Ż��

	/*
	#define _CRT_SECURE_NO_WARNINGS
	#include<stdio.h>
	int main()
	{
		char c1;
		scanf("%d",&c1);
		for(; c1 <= 'z' ; c1++)
		{
			printf("%c\n",c1);
		}


	}
	*/

	return 0;
}	