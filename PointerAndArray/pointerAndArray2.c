#include<stdio.h>
int main()
{
	/*
	FizzBuzz -> ������ ���α׷��� ����
	1���� 100���� ���
	3�� ����� Fizz���
	5�� ����� Buzz���
	3�� 5�� ������� FizzBuzz ���
	*/

	int i;

	for (i = 1; i <= 100; i++)
	{
		if (i % 3 == 0 && i % 5 == 0)
			printf("FizzBuzz\n");
		else if (i % 3 == 0)
			printf("Fizz\n");
		else if (i % 5 == 0)
			printf("Buzz\n");
		else
			printf("%d\n", i);
	}

	for (int i = 0; ++i <= 100;)
		printf(i % 3 ? i % 5 ? "%d\n" : "Buzz\n"
			: i % 5 ? "Fizz\n" : "FizzBuzz\n", i);
	//�ڵ� ���� ��� : �ҽ��ڵ��� ���� ���� �ִ��� �ٿ���
	//�ۼ��ϴ� ����
	//i % 3�� ����Ͽ� 0�� �ƴϸ� i % 5�� ��, i % 5�� 0��
	//�ƴϸ� %d�� i�� �����
	//i % 5�� 0�̸� "Buzz"�� �����
	//i % 3�� 0�̸� �ٽ� i % 5�� ����ؼ� 0�� �ƴ� ����
	//������ 3�� ����̹Ƿ� "Fizz"�� �����
	//i % 3, i % 5�� �� �� 0�̸� "FizzBuzz"�� �����

	/*
	#define _CRT_SECURE_NO_WARNINGS
	#include<stdio.h>
	int main()
	{
		int num1, num2;
		scanf("%d %d", &num1, &num2);

		for(;num1 <= num2; num1++)
		{
			if(num1 % 5 == 0 && num1 % 11 == 0)
				printf("FizzBuzz\n");
			else if(num1 % 5 ==0)
				printf("Fizz\n");
			else if(num1 % 11 ==0)
				printf("Buzz\n");
			else
				printf("%d\n", num1);
		}







	}
	*/









	return 0;

}