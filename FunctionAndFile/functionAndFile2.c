#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void hello(int count)
{
	if (count == 0)
		return;

	printf("Hello, world! %d\n", count);

	hello(--count);

	//hello 함수가 재귀호출을 할 때마다 count가 1씩 감소하고
	//count가 0이면 종료됨
}

int factorial(int n)
{
	if (n == 1)
		return 1;

	return n * factorial(n - 1);	
	/*
	계산 결과가 즉시 구해지는 것이 아니라 재귀 호출로 n-1을 계속
	전달하다가 n이 1일때 비로소 1을 반환하면서 n과 곱하고 다시 
	결과값을 반환함. 5*factorial(4) -> 5*4*factorial(3)
	->5*4*3*factorial(2) -> 5*4*3*2*factorial(1)
	->5*4*3*2*1-> 120을 반환함
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
	함수 안에서 함수 자기자신을 호출하는 방식을 재귀호출이라고 함
	일반적인 상황에서는 잘 사용하지 않음 
	알고리즘을 구현할 때 매우 유용함	
	*/

	hello(5);

	/*
	컴파일 해보면 Hello, world!가 계속 출력되다가 프로그램이
	종료됨, 왜냐하면 hello 함수가 자기자신을 계속 호출하다가
	스택이 넘쳐서 스택 오버플로우 에러가 발생하기 때문
	(함수 호출은 메모리의 스택을 사용함)
	재귀호출을 사용하려면 반드시 다음과 같이 종료 조건을 만들어
	주어야 함
	*/


	/*
	재귀호출로 팩토리얼(factorial) 구하기, 팩토리얼(factorial)은
	1부터 n까지 숫자를 차례대로 곱한값
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