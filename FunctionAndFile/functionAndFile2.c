#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void hello(int count)
{
	if (count == 0)
		return;

	printf("Hello, world! %d\n", count);

	hello(--count);

	//hello �Լ��� ���ȣ���� �� ������ count�� 1�� �����ϰ�
	//count�� 0�̸� �����
}

int factorial(int n)
{
	if (n == 1)
		return 1;

	return n * factorial(n - 1);	
	/*
	��� ����� ��� �������� ���� �ƴ϶� ��� ȣ��� n-1�� ���
	�����ϴٰ� n�� 1�϶� ��μ� 1�� ��ȯ�ϸ鼭 n�� ���ϰ� �ٽ� 
	������� ��ȯ��. 5*factorial(4) -> 5*4*factorial(3)
	->5*4*3*factorial(2) -> 5*4*3*2*factorial(1)
	->5*4*3*2*1-> 120�� ��ȯ��
	*/

}

int fib(int n)
{
	if ((n == 2) || (n == 1))
		return 1;

	return fib(n - 1) + fib(n - 2);

}

int sum(int n)
{
	if (n == 1)
		return 1;

	return n + sum(n - 1);

}

int twosum(int n)
{
	if (n % 2 == 0)
		return (n + 1)*(n / 2);
	else
		return (n + 1)*(n / 2) + (n / 2) + 1;
}


int main()
{
	/*
	�Լ� �ȿ��� �Լ� �ڱ��ڽ��� ȣ���ϴ� ����� ���ȣ���̶�� ��
	�Ϲ����� ��Ȳ������ �� ������� ���� 
	�˰����� ������ �� �ſ� ������	
	*/

	hello(5);

	/*
	������ �غ��� Hello, world!�� ��� ��µǴٰ� ���α׷���
	�����, �ֳ��ϸ� hello �Լ��� �ڱ��ڽ��� ��� ȣ���ϴٰ�
	������ ���ļ� ���� �����÷ο� ������ �߻��ϱ� ����
	(�Լ� ȣ���� �޸��� ������ �����)
	���ȣ���� ����Ϸ��� �ݵ�� ������ ���� ���� ������ �����
	�־�� ��
	*/


	/*
	���ȣ��� ���丮��(factorial) ���ϱ�, ���丮��(factorial)��
	1���� n���� ���ڸ� ���ʴ�� ���Ѱ�
	*/

	printf("%d\n", factorial(5));

	/*
	
	int fib(int n)
	{	
		if((n == 0)||(n == 1))
			return n;
		
		return fib(n-1) + fib(n-2) ;
	
	}
	
	*/

	int num1;

	scanf("%d", &num1);

	printf("%d\n", fib(num1));


	printf("%d\n", sum(101));
	printf("%d\n", twosum(101));




	return 0;
}